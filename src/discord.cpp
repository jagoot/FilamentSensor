/*
 * Discord Notification Module
 */

#include "discord.h"
#include <HTTPClient.h>
#include <Preferences.h>

// Preferences namespace
static Preferences preferences;

// Discord settings
static bool discordEnabled = false;
static String discordWebhookUrl = "";

// Rate limiting
static unsigned long lastNotificationTime = 0;
static const unsigned long NOTIFICATION_COOLDOWN = 5000;  // 5 seconds between notifications (Discord limit is higher)

void setupDiscord() {
  // Load settings from flash
  preferences.begin("discord", false);

  discordEnabled = preferences.getBool("enabled", false);
  discordWebhookUrl = preferences.getString("webhook", "");

  preferences.end();

  Serial.println("[DISCORD] Module initialized");
  Serial.printf("[DISCORD]   Enabled: %s\n", discordEnabled ? "Yes" : "No");
  Serial.printf("[DISCORD]   Webhook: %s\n", discordWebhookUrl.length() > 0 ? "***" : "(not set)");
}

void sendDiscordNotification(const char* message) {
  // Check if enabled and configured
  if (!discordEnabled) {
    Serial.println("[DISCORD] Notifications disabled");
    return;
  }

  if (discordWebhookUrl.length() == 0) {
    Serial.println("[DISCORD] Webhook URL not configured");
    return;
  }

  // Rate limiting - avoid spamming
  unsigned long now = millis();
  if (now - lastNotificationTime < NOTIFICATION_COOLDOWN) {
    Serial.printf("[DISCORD] Rate limit: %lu ms remaining\n",
                  NOTIFICATION_COOLDOWN - (now - lastNotificationTime));
    return;
  }

  Serial.printf("[DISCORD] Sending notification: %s\n", message);

  HTTPClient http;
  http.begin(discordWebhookUrl);
  http.addHeader("Content-Type", "application/json");

  // Build JSON payload for Discord webhook
  String jsonPayload = "{\"content\":\"" + String(message) + "\"}";
  // Escape newlines for JSON
  jsonPayload.replace("\n", "\\n");

  int httpCode = http.POST(jsonPayload);

  if (httpCode > 0) {
    Serial.printf("[DISCORD] Response: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_NO_CONTENT) {
      Serial.println("[DISCORD] ✅ Notification sent successfully");
      lastNotificationTime = now;
    } else {
      Serial.printf("[DISCORD] ❌ Error: %s\n", http.getString().c_str());
    }
  } else {
    Serial.printf("[DISCORD] ❌ Request failed: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

bool getDiscordEnabled() {
  return discordEnabled;
}

void setDiscordEnabled(bool enabled) {
  discordEnabled = enabled;

  preferences.begin("discord", false);
  preferences.putBool("enabled", enabled);
  preferences.end();

  Serial.printf("[DISCORD] Enabled: %s\n", enabled ? "Yes" : "No");
}

String getDiscordWebhookUrl() {
  return discordWebhookUrl;
}

void setDiscordWebhookUrl(const String& webhookUrl) {
  discordWebhookUrl = webhookUrl;

  preferences.begin("discord", false);
  preferences.putString("webhook", webhookUrl);
  preferences.end();

  Serial.println("[DISCORD] Webhook URL updated");
}

void notifyFilamentError(const char* errorType) {
  char message[200];
  snprintf(message, sizeof(message),
           "🚨 **Centauri Carbon Alarm!**\\n\\n%s detected!\\n\\nPrint has been paused.",
           errorType);
  sendDiscordNotification(message);
}

void notifyPrintComplete(const char* filename, unsigned long duration) {
  char message[200];
  unsigned long hours = duration / 3600000;
  unsigned long minutes = (duration % 3600000) / 60000;

  snprintf(message, sizeof(message),
           "✅ **Print completed!**\\n\\nFile: %s\\nDuration: %luh %lumin",
           filename, hours, minutes);
  sendDiscordNotification(message);
}

void notifyPrintStarted(const char* filename) {
  char message[200];
  snprintf(message, sizeof(message),
           "🖨️ **Print started**\\n\\nFile: %s",
           filename);
  sendDiscordNotification(message);
}

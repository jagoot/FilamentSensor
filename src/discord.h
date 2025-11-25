/*
 * Discord Notification Module
 * Sends notifications via Discord Webhook
 */

#ifndef DISCORD_H
#define DISCORD_H

#include <Arduino.h>

// Initialize Discord module
void setupDiscord();

// Send Discord notification
void sendDiscordNotification(const char* message);

// Get/Set Discord settings
bool getDiscordEnabled();
void setDiscordEnabled(bool enabled);

String getDiscordWebhookUrl();
void setDiscordWebhookUrl(const String& webhookUrl);

// Notification types
void notifyFilamentError(const char* errorType);
void notifyPrintComplete(const char* filename, unsigned long duration);
void notifyPrintStarted(const char* filename);

#endif // DISCORD_H

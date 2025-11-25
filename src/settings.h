/*
 * Settings Page HTML
 * Configuration, OTA Updates, and Testing
 */

#ifndef SETTINGS_H
#define SETTINGS_H

const char* getSettingsHTML() {
  return R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Settings - Centauri Monitor</title>
  <style>
    * { margin: 0; padding: 0; box-sizing: border-box; }

    body {
      font-family: 'Segoe UI', system-ui, sans-serif;
      background: linear-gradient(135deg, #1e3c72 0%, #2a5298 100%);
      color: #fff;
      min-height: 100vh;
      padding: 20px;
    }

    .container {
      max-width: 800px;
      margin: 0 auto;
    }

    header {
      text-align: center;
      margin-bottom: 30px;
      padding: 20px;
      background: rgba(255,255,255,0.1);
      border-radius: 15px;
      backdrop-filter: blur(10px);
    }

    h1 {
      font-size: 2.5em;
      margin-bottom: 10px;
      text-shadow: 2px 2px 4px rgba(0,0,0,0.3);
    }

    .nav-buttons {
      display: flex;
      gap: 10px;
      margin-bottom: 20px;
    }

    .btn {
      padding: 12px 24px;
      border: none;
      border-radius: 8px;
      font-size: 1em;
      cursor: pointer;
      transition: all 0.3s ease;
      font-weight: 600;
      flex: 1;
    }

    .btn-primary {
      background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
      color: white;
    }

    .btn-primary:hover {
      transform: translateY(-2px);
      box-shadow: 0 5px 15px rgba(102, 126, 234, 0.4);
    }

    .settings-section {
      background: rgba(255, 255, 255, 0.1);
      backdrop-filter: blur(10px);
      border-radius: 15px;
      padding: 25px;
      margin-bottom: 20px;
      box-shadow: 0 8px 32px rgba(0, 0, 0, 0.1);
    }

    .settings-section h2 {
      margin-bottom: 20px;
      font-size: 1.5em;
      border-bottom: 2px solid rgba(255,255,255,0.2);
      padding-bottom: 10px;
    }

    .form-group {
      margin-bottom: 15px;
    }

    .form-group label {
      display: block;
      margin-bottom: 5px;
      font-weight: 600;
    }

    .form-group input {
      width: 100%;
      padding: 10px;
      border-radius: 5px;
      border: 1px solid rgba(255,255,255,0.3);
      background: rgba(255,255,255,0.1);
      color: #fff;
      font-size: 1em;
    }

    .form-group input::placeholder {
      color: rgba(255,255,255,0.5);
    }

    .controls {
      display: flex;
      gap: 10px;
      flex-wrap: wrap;
      margin-top: 15px;
    }

    .btn-success {
      background: linear-gradient(135deg, #11998e 0%, #38ef7d 100%);
      color: white;
    }

    .btn-success:hover {
      transform: translateY(-2px);
      box-shadow: 0 5px 15px rgba(56, 239, 125, 0.4);
    }

    .btn-secondary {
      background: rgba(255,255,255,0.2);
      color: white;
    }

    .btn-secondary:hover {
      background: rgba(255,255,255,0.3);
    }

    .btn-warning {
      background: linear-gradient(135deg, #f093fb 0%, #f5576c 100%);
      color: white;
    }

    .btn-danger {
      background: linear-gradient(135deg, #eb3349 0%, #f45c43 100%);
      color: white;
    }

    .status-message {
      margin-top: 10px;
      padding: 10px;
      border-radius: 5px;
      text-align: center;
      font-weight: bold;
    }

    .info-row {
      display: flex;
      justify-content: space-between;
      padding: 10px 0;
      border-bottom: 1px solid rgba(255,255,255,0.1);
    }

    .info-label {
      opacity: 0.8;
    }

    .info-value {
      font-weight: 600;
    }

    #otaProgress, #runoutTestResult {
      margin-top: 15px;
    }

    .progress-bar-container {
      background: rgba(255,255,255,0.2);
      border-radius: 10px;
      overflow: hidden;
      height: 30px;
    }

    .progress-bar {
      background: #4CAF50;
      height: 100%;
      width: 0%;
      transition: width 0.3s;
      display: flex;
      align-items: center;
      justify-content: center;
      font-weight: bold;
    }

    .test-result {
      padding: 10px;
      background: rgba(0,0,0,0.3);
      border-radius: 5px;
      font-family: monospace;
      font-size: 0.9em;
      text-align: center;
      font-weight: bold;
    }

    @media (max-width: 768px) {
      h1 { font-size: 1.8em; }
      .btn { width: 100%; margin: 5px 0; }
      .controls { flex-direction: column; }
    }
  </style>
</head>
<body>
  <div class="container">
    <header>
      <h1>⚙️ Settings</h1>
      <p>Configuration & Management</p>
    </header>

    <div class="nav-buttons">
      <button class="btn btn-primary" onclick="window.location.href='/'">
        🏠 Back to Dashboard
      </button>
    </div>

    <!-- WiFi & Printer Settings -->
    <div class="settings-section">
      <h2>🌐 Network & Printer</h2>

      <div class="form-group">
        <label>WiFi SSID:</label>
        <input type="text" id="wifiSSID" placeholder="SSID">
      </div>

      <div class="form-group">
        <label>WiFi Password:</label>
        <input type="password" id="wifiPassword" placeholder="Password">
      </div>

      <div class="form-group">
        <label>Printer IP Address:</label>
        <input type="text" id="printerIP" placeholder="192.168.1.100">
      </div>

      <div class="form-group">
        <label>Printer Port:</label>
        <input type="number" id="printerPort" placeholder="80" value="80">
      </div>

      <div class="controls">
        <button class="btn btn-success" onclick="saveSettings()">
          💾 Save
        </button>
        <button class="btn btn-secondary" onclick="loadSettings()">
          🔄 Reload
        </button>
      </div>

      <div id="settingsStatus" class="status-message" style="display:none;"></div>
    </div>

    <!-- Discord Notifications -->
    <div class="settings-section">
      <h2>🎮 Discord Notifications</h2>

      <div class="form-group">
        <label>
          <input type="checkbox" id="discordEnabled" style="width: auto;">
          Enable notifications
        </label>
      </div>

      <div class="form-group">
        <label>Discord Webhook URL:</label>
        <input type="text" id="discordWebhook" placeholder="https://discord.com/api/webhooks/...">
        <small style="color: #888;">
          Create webhook: Server Settings → Integrations → Webhooks → New Webhook
        </small>
      </div>

      <div class="controls">
        <button class="btn btn-success" onclick="saveDiscordSettings()">
          💾 Save
        </button>
        <button class="btn btn-secondary" onclick="testNotification()">
          📤 Send test message
        </button>
      </div>

      <div id="discordStatus" class="status-message" style="display:none;"></div>
    </div>

    <!-- OTA Update Section -->
    <div class="settings-section">
      <h2>🔄 Firmware Update (OTA)</h2>

      <div class="info-row">
        <span class="info-label">Current Partition:</span>
        <span class="info-value" id="currentPartition">-</span>
      </div>
      <div class="info-row">
        <span class="info-label">Next Partition:</span>
        <span class="info-value" id="nextPartition">-</span>
      </div>

      <div class="controls" style="margin-top: 20px;">
        <input type="file" id="firmwareFile" accept=".bin" style="display: none;" onchange="uploadFirmware()">
        <button class="btn btn-success" onclick="document.getElementById('firmwareFile').click()">
          📁 Select firmware
        </button>
        <button class="btn btn-secondary" onclick="checkOTAStatus()">
          📊 Check status
        </button>
      </div>

      <div id="otaProgress" style="display: none;">
        <div class="progress-bar-container">
          <div id="otaProgressBar" class="progress-bar">0%</div>
        </div>
          <div id="otaStatus" style="margin-top: 10px; text-align: center;">Waiting for upload...</div>
      </div>
    </div>

    <!-- Runout Pin Test Section -->
    <div class="settings-section">
      <h2>🔧 Runout Pin Test (IO2)</h2>
      <p style="opacity: 0.8; margin-bottom: 15px;">
        Manual testing of the runout pin. In normal operation SENSOR_SWITCH is automatically passed through.
      </p>

      <div class="controls">
        <button class="btn btn-success" onclick="setRunoutOutput(true)">
          ⬆️ Set HIGH
        </button>
        <button class="btn btn-danger" onclick="setRunoutOutput(false)">
          ⬇️ Set LOW
        </button>
      </div>

      <div style="margin-top: 10px;">
        <button class="btn btn-secondary" onclick="readRunoutState()" style="width: 100%;">
          📖 Read current state
        </button>
      </div>

      <div id="runoutTestResult" class="test-result">
        Click a button to control IO2
      </div>
    </div>

  </div>

  <script>
    // Load settings on page load
    window.onload = function() {
      loadSettings();
      checkOTAStatus();
    };

    async function loadSettings() {
      try {
        const response = await fetch('/api/config');
        const data = await response.json();

        document.getElementById('wifiSSID').value = data.wifiSSID || '';
        document.getElementById('printerIP').value = data.printerIP || '';
        document.getElementById('printerPort').value = data.printerPort || 80;

        showStatus('settingsStatus', '✅ Settings loaded', 'success');

        // Load Discord settings
        loadDiscordSettings();
      } catch (error) {
        console.error('Error loading:', error);
        showStatus('settingsStatus', '❌ Error loading', 'error');
      }
    }

    async function loadDiscordSettings() {
      try {
        const response = await fetch('/api/status');
        const data = await response.json();

        if (data.notify) {
          document.getElementById('discordEnabled').checked = data.notify.enabled || false;
          // Don't load webhook URL for security (show placeholder if set)
          if (data.notify.hasWebhook) {
            document.getElementById('discordWebhook').placeholder = '****** (saved)';
          }
        }
      } catch (error) {
        console.error('Error loading Discord settings:', error);
      }
    }

    async function saveDiscordSettings() {
      const enabled = document.getElementById('discordEnabled').checked;
      const webhookUrl = document.getElementById('discordWebhook').value;

      try {
        const response = await fetch('/api/control', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({
            action: 'setDiscordSettings',
            enabled: enabled,
            webhookUrl: webhookUrl
          })
        });

        const data = await response.json();

        if (data.success) {
          showStatus('discordStatus', '✅ ' + data.message, 'success');
          // Clear webhook field after successful save
          document.getElementById('discordWebhook').value = '';
          document.getElementById('discordWebhook').placeholder = '****** (saved)';
        } else {
          showStatus('discordStatus', '❌ ' + data.message, 'error');
        }
      } catch (error) {
        console.error('Error saving:', error);
        showStatus('discordStatus', '❌ Error saving', 'error');
      }
    }

    async function testNotification() {
      try {
        const response = await fetch('/api/control', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ action: 'testNotification' })
        });

        const data = await response.json();

        if (data.success) {
          showStatus('discordStatus', '✅ Test message sent!', 'success');
        } else {
          showStatus('discordStatus', '❌ ' + data.message, 'error');
        }
      } catch (error) {
        console.error('Error:', error);
        showStatus('discordStatus', '❌ Error sending', 'error');
      }
    }

    async function saveSettings() {
      const wifiSSID = document.getElementById('wifiSSID').value;
      const wifiPassword = document.getElementById('wifiPassword').value;
      const printerIP = document.getElementById('printerIP').value;
      const printerPort = parseInt(document.getElementById('printerPort').value) || 80;

      if (!printerIP) {
        alert('Please enter at least one printer IP!');
        return;
      }

      const ipPattern = /^(\d{1,3}\.){3}\d{1,3}$/;
      if (!ipPattern.test(printerIP)) {
        alert('Invalid IP address!');
        return;
      }

      const config = {
        printerIP: printerIP,
        printerPort: printerPort
      };

      if (wifiSSID && wifiPassword) {
        config.wifiSSID = wifiSSID;
        config.wifiPassword = wifiPassword;
      }

      try {
        const response = await fetch('/api/config', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify(config)
        });

        const result = await response.json();

        if (result.success) {
          showStatus('settingsStatus', '✅ ' + result.message, 'success');

          if (result.needsRestart) {
            if (confirm('Settings saved!\n\nWiFi changes require a restart.\nRestart now?')) {
              await fetch('/api/control', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ action: 'restart' })
              });
              alert('ESP32 is restarting...\nPlease wait 10 seconds.');
            }
          }
        } else {
          showStatus('settingsStatus', '❌ ' + result.message, 'error');
        }
      } catch (error) {
        console.error('Error saving:', error);
        showStatus('settingsStatus', '❌ Error saving', 'error');
      }
    }

    async function checkOTAStatus() {
      try {
        const response = await fetch('/api/ota/status');
        const data = await response.json();

        document.getElementById('currentPartition').textContent = data.currentPartition;
        document.getElementById('nextPartition').textContent = data.nextPartition;
      } catch (error) {
        console.error('OTA status error:', error);
      }
    }

    async function uploadFirmware() {
      const fileInput = document.getElementById('firmwareFile');
      const file = fileInput.files[0];

      if (!file) return;

      if (!file.name.endsWith('.bin')) {
        alert('Please select only .bin files!');
        return;
      }

      if (!confirm('Upload firmware "' + file.name + '"?\n\nThe ESP32 will restart after a successful upload.')) {
        fileInput.value = '';
        return;
      }

      const formData = new FormData();
      formData.append('firmware', file);

      const progressDiv = document.getElementById('otaProgress');
      const progressBar = document.getElementById('otaProgressBar');
      const statusDiv = document.getElementById('otaStatus');

      progressDiv.style.display = 'block';
      progressBar.style.width = '0%';
      progressBar.textContent = '0%';
      statusDiv.textContent = 'Uploading...';

      try {
        const xhr = new XMLHttpRequest();

        xhr.upload.addEventListener('progress', (e) => {
          if (e.lengthComputable) {
            const percentComplete = Math.round((e.loaded / e.total) * 100);
            progressBar.style.width = percentComplete + '%';
            progressBar.textContent = percentComplete + '%';
          }
        });

        xhr.addEventListener('load', () => {
          if (xhr.status === 200) {
            const response = JSON.parse(xhr.responseText);
            progressBar.style.width = '100%';
            progressBar.textContent = '100%';
            statusDiv.textContent = response.message || 'Upload successful! Restarting...';
            progressBar.style.background = '#4CAF50';

            setTimeout(() => {
              alert('Firmware updated successfully!\n\nThe ESP32 is now restarting.\nPlease wait about 10 seconds and reload the page.');
            }, 1000);
          } else {
            const response = JSON.parse(xhr.responseText);
            statusDiv.textContent = 'Error: ' + (response.message || 'Upload failed');
            progressBar.style.background = '#dc3545';
            alert('Upload failed: ' + (response.message || 'Unknown error'));
          }
          fileInput.value = '';
        });

        xhr.addEventListener('error', () => {
          statusDiv.textContent = 'Upload failed';
          progressBar.style.background = '#dc3545';
          alert('Upload failed: Network error');
          fileInput.value = '';
        });

        xhr.open('POST', '/api/ota/upload');
        xhr.send(formData);

      } catch (error) {
        console.error('Upload error:', error);
        statusDiv.textContent = 'Error: ' + error.message;
        progressBar.style.background = '#dc3545';
        alert('Upload failed: ' + error.message);
        fileInput.value = '';
      }
    }

    async function setRunoutOutput(state) {
      try {
        const resultDiv = document.getElementById('runoutTestResult');
        resultDiv.textContent = state ? 'Setting IO2 to HIGH...' : 'Setting IO2 to LOW...';
        resultDiv.style.color = '#ffc107';

        const response = await fetch('/api/test/runout/set?state=' + (state ? '1' : '0'));
        const data = await response.json();

        if (data.success) {
          resultDiv.textContent = state ? '✅ IO2 = HIGH set' : '✅ IO2 = LOW set';
          resultDiv.style.color = state ? '#4CAF50' : '#dc3545';
          resultDiv.style.fontSize = '1.2em';
        } else {
          resultDiv.textContent = 'Error: ' + data.message;
          resultDiv.style.color = '#dc3545';
        }
      } catch (error) {
        console.error('Runout set error:', error);
        const resultDiv = document.getElementById('runoutTestResult');
        resultDiv.textContent = 'Error: ' + error.message;
        resultDiv.style.color = '#dc3545';
      }
    }

    async function readRunoutState() {
      try {
        const resultDiv = document.getElementById('runoutTestResult');
        resultDiv.textContent = 'Reading pin IO2...';
        resultDiv.style.color = '#ffc107';

        const response = await fetch('/api/test/runout/read');
        const data = await response.json();

        if (data.success) {
          resultDiv.textContent = data.result;
          const isHigh = data.result.includes('HIGH');
          resultDiv.style.color = isHigh ? '#4CAF50' : '#ffc107';
          resultDiv.style.fontSize = '1.2em';
        } else {
          resultDiv.textContent = 'Error: ' + data.message;
          resultDiv.style.color = '#dc3545';
        }
      } catch (error) {
        console.error('Runout read error:', error);
        const resultDiv = document.getElementById('runoutTestResult');
        resultDiv.textContent = 'Error: ' + error.message;
        resultDiv.style.color = '#dc3545';
      }
    }

    function showStatus(elementId, message, type) {
      const statusDiv = document.getElementById(elementId);
      statusDiv.style.display = 'block';
      statusDiv.textContent = message;
      statusDiv.style.background = type === 'success' ? 'rgba(76, 175, 80, 0.3)' : 'rgba(244, 67, 54, 0.3)';
      statusDiv.style.color = type === 'success' ? '#4CAF50' : '#f44336';

      setTimeout(() => {
        statusDiv.style.display = 'none';
      }, 5000);
    }
  </script>
</body>
</html>
  )rawliteral";
}

#endif // SETTINGS_H

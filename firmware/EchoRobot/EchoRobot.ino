/*
  ECHO — ESP32-S3 Gemini voice robot
  Starter firmware scaffold.

  Confirm GPIO assignments in config.h before connecting hardware.
  Audio/Gemini integration points are intentionally explicit TODOs.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include "config.h"
#include "secrets.h"
#include "audio_io.h"
#include "gemini_client.h"

Servo headServo;
Servo armServo;

static void connectWiFi() {
  Serial.printf("Connecting to Wi-Fi: %s\n", WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  const unsigned long started = millis();
  while (WiFi.status() != WL_CONNECTED &&
         millis() - started < WIFI_CONNECT_TIMEOUT_MS) {
    delay(300);
    Serial.print(".");
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Wi-Fi connected. IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Wi-Fi connection timed out. Check secrets.h and network.");
  }
}

static void setupServos() {
  headServo.setPeriodHertz(SERVO_FREQUENCY_HZ);
  armServo.setPeriodHertz(SERVO_FREQUENCY_HZ);
  headServo.attach(HEAD_SERVO_PIN, SERVO_MIN_US, SERVO_MAX_US);
  armServo.attach(ARM_SERVO_PIN, SERVO_MIN_US, SERVO_MAX_US);
  headServo.write(SERVO_NEUTRAL_DEG);
  armServo.write(SERVO_NEUTRAL_DEG);
}

static void moveToListeningPose() {
  headServo.write(HEAD_LISTEN_DEG);
}

static void moveToThinkingPose() {
  headServo.write(HEAD_THINK_DEG);
}

static void moveToSpeakingPose() {
  armServo.write(ARM_SPEAK_DEG);
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\nECHO booting...");

  setupServos();

  if (!audioBegin()) {
    Serial.println("Audio hardware init failed; check I2S pins and power.");
  }

  connectWiFi();

  if (WiFi.status() == WL_CONNECTED) {
    geminiBegin(GEMINI_API_KEY, GEMINI_MODEL);
  }

  Serial.println("ECHO ready. Type a test prompt in Serial Monitor.");
  Serial.println("NOTE: microphone capture / Gemini audio / TTS playback are TODO adapters.");
}

void loop() {
  if (Serial.available()) {
    String prompt = Serial.readStringUntil('\n');
    prompt.trim();

    if (prompt.length() > 0) {
      moveToThinkingPose();

      if (WiFi.status() != WL_CONNECTED) {
        connectWiFi();
      }

      String reply;
      if (geminiSendText(prompt, reply)) {
        Serial.print("ECHO: ");
        Serial.println(reply);
        moveToSpeakingPose();
        // TODO: pass reply to a text-to-speech service and play decoded PCM.
      } else {
        Serial.println("Gemini request failed. Check API key, model, network and quota.");
      }

      delay(250);
      headServo.write(SERVO_NEUTRAL_DEG);
      armServo.write(SERVO_NEUTRAL_DEG);
    }
  }

  // TODO: implement push-to-talk / wake-word / voice activity detection.
  delay(10);
}

#include "gemini_client.h"
#include "config.h"
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

static String s_apiKey;
static String s_model;

void geminiBegin(const char *apiKey, const char *model) {
  s_apiKey = apiKey;
  s_model = model;
}

bool geminiSendText(const String &prompt, String &reply) {
  if (WiFi.status() != WL_CONNECTED || s_apiKey.isEmpty() || s_model.isEmpty()) {
    Serial.println("Gemini unavailable: Wi-Fi, API key or model missing.");
    return false;
  }

  WiFiClientSecure client;
  // For a real deployment, validate the server certificate.
  // setInsecure() is used here only as a temporary bring-up shortcut.
  // Replace with setCACert(...) before public release.
  client.setInsecure();

  HTTPClient http;
  const String url = "https://generativelanguage.googleapis.com/v1beta/models/" +
                     s_model + ":generateContent?key=" + s_apiKey;

  if (!http.begin(client, url)) return false;
  http.setTimeout(GEMINI_HTTP_TIMEOUT_MS);
  http.addHeader("Content-Type", "application/json");

  JsonDocument request;
  JsonArray contents = request["contents"].to<JsonArray>();
  JsonObject content = contents.add<JsonObject>();
  JsonArray parts = content["parts"].to<JsonArray>();
  JsonObject part = parts.add<JsonObject>();
  part["text"] = prompt;

  String body;
  serializeJson(request, body);

  const int status = http.POST(body);
  const String response = http.getString();
  http.end();

  if (status < 200 || status >= 300) {
    Serial.printf("Gemini HTTP error: %d\n", status);
    Serial.println(response);
    return false;
  }

  JsonDocument parsed;
  const DeserializationError error = deserializeJson(parsed, response);
  if (error) {
    Serial.printf("Gemini JSON parse error: %s\n", error.c_str());
    return false;
  }

  // Safely check candidate/content/parts before reading response text.
  JsonVariant textNode = parsed["candidates"][0]["content"]["parts"][0]["text"];
  if (textNode.isNull()) {
    Serial.println("Gemini response did not contain text.");
    return false;
  }

  reply = textNode.as<String>();
  return true;
}

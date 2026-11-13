#pragma once
#include <Arduino.h>

void geminiBegin(const char *apiKey, const char *model);
bool geminiSendText(const String &prompt, String &reply);

// TODO: Add an audio-input method only after choosing and validating
// the exact Gemini model/API audio format and response modality.

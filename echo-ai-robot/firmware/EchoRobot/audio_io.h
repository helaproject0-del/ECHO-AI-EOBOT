#pragma once
#include <Arduino.h>

// Audio hardware abstraction.
// TODO: Implement I2S RX for INMP441 and I2S TX for MAX98357A using
// the I2S API supported by the installed ESP32 Arduino core version.

bool audioBegin();
bool audioReadPcm(int16_t *destination, size_t sampleCount);
bool audioPlayPcm(const int16_t *samples, size_t sampleCount);

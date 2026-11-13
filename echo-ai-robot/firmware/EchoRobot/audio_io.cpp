#include "audio_io.h"
#include "config.h"

bool audioBegin() {
  // TODO:
  // 1. Configure I2S RX (BCLK, WS, DATA) for INMP441.
  // 2. Configure I2S TX (BCLK, LRC, DIN) for MAX98357A.
  // 3. Confirm channel format and sample alignment on the actual board.
  Serial.println("TODO: configure INMP441 and MAX98357A I2S.");
  return false;
}

bool audioReadPcm(int16_t *destination, size_t sampleCount) {
  (void)destination;
  (void)sampleCount;
  // TODO: read I2S samples, convert/shift to signed 16-bit mono PCM.
  return false;
}

bool audioPlayPcm(const int16_t *samples, size_t sampleCount) {
  (void)samples;
  (void)sampleCount;
  // TODO: write PCM samples to I2S TX; handle partial writes and timeouts.
  return false;
}

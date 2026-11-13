#pragma once

// TODO: Replace every pin with the GPIOs used in your actual wiring.
// Check the pinout for your exact ESP32-S3 board; some pins may be reserved.

#define I2S_MIC_BCLK_PIN   4
#define I2S_MIC_WS_PIN     5
#define I2S_MIC_DOUT_PIN   6

#define I2S_AMP_BCLK_PIN   15
#define I2S_AMP_LRC_PIN    16
#define I2S_AMP_DIN_PIN    17

#define HEAD_SERVO_PIN     12
#define ARM_SERVO_PIN      13

#define AUDIO_SAMPLE_RATE       16000
#define AUDIO_BITS_PER_SAMPLE   16
#define AUDIO_BUFFER_SAMPLES    512

#define SERVO_FREQUENCY_HZ 50
#define SERVO_MIN_US       500
#define SERVO_MAX_US       2400
#define SERVO_NEUTRAL_DEG  90
#define HEAD_LISTEN_DEG    75
#define HEAD_THINK_DEG     105
#define ARM_SPEAK_DEG      120

#define WIFI_CONNECT_TIMEOUT_MS 20000
#define GEMINI_HTTP_TIMEOUT_MS  20000

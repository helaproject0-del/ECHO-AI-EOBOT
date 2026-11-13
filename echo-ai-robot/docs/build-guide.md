# Build guide

## 1. Prepare the software

- Install Arduino IDE 2.x or PlatformIO.
- Install Espressif's ESP32 board support.
- Install `ESP32Servo` and `ArduinoJson`.
- Select the exact ESP32-S3 board variant.

## 2. Configure credentials

Copy `secrets.example.h` to `secrets.h`. Enter Wi-Fi credentials and a Google AI Studio API key. Keep `secrets.h` private.

## 3. Confirm the pin map

Edit `config.h` to match the real wiring. Check for GPIO restrictions on your exact board.

## 4. Bring up one subsystem at a time

1. Boot and serial output.
2. Wi-Fi connection.
3. One servo at a time.
4. INMP441 input test.
5. MAX98357A output test with a short, low-volume test signal.
6. Gemini text request.
7. Audio encoding/request/response decoding.
8. Full conversation loop and movement.

## 5. Audio pipeline still to implement

The current scaffold does not yet implement I2S capture/playback or Gemini audio/TTS. Choose the exact Gemini model and supported audio modality first, then implement:
- microphone capture and voice activity detection or push-to-talk;
- PCM framing, sample-rate/channel conversion and encoding;
- request format required by the chosen model;
- response text/audio parsing and audio decoding;
- playback buffering and interruption handling.

Do not describe the robot as fully voice-enabled until this pipeline has been implemented and tested.

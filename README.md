# ECHO — Gemini-powered voice companion robot

ECHO is a small, voice-enabled robot built around an **ESP32-S3**. The planned hardware includes an **INMP441 I2S microphone**, a **MAX98357A I2S amplifier + speaker**, and **two servos** for movement. It connects to the Google Gemini API for conversational intelligence.

> **Project status: starter repository / integration scaffold.** The hardware list is based on the project description. GPIO assignments, exact board variant, servo mechanics, audio pipeline, and the working firmware were not supplied, so the pin map and some integration steps are intentionally marked `TODO`. Do not claim that an untested feature is complete.

## Features planned

- Capture voice through an INMP441 microphone.
- Send a user prompt/audio to Gemini and receive a response.
- Play spoken responses through the MAX98357A and speaker.
- Move two servos in response to commands or conversation.
- Keep Wi-Fi credentials and API keys out of source control.

## Hardware

| Part | Purpose |
|---|---|
| ESP32-S3 development board | Main controller and Wi-Fi |
| INMP441 | I2S digital microphone |
| MAX98357A | I2S audio amplifier |
| Speaker compatible with the amplifier | Audio output |
| 2 × hobby servos | Robot movement |
| Stable regulated power supply | Board, audio and servo power |
| Jumper wires / breadboard or custom PCB | Connections |

See [`hardware/README.md`](hardware/README.md) and [`hardware/wiring.md`](hardware/wiring.md).

## Repository layout

```text
.
├── firmware/EchoRobot/       # Arduino/PlatformIO-ready firmware scaffold
├── hardware/                 # Parts, wiring and pin-map notes
├── docs/                     # Build, test and submission notes
├── .github/                  # Issue template
├── .gitignore
├── LICENSE
└── README.md
```

## Quick start

1. Install Arduino IDE 2.x or PlatformIO.
2. Install the Espressif ESP32 board package and the **ESP32Servo** library.
3. Open `firmware/EchoRobot/EchoRobot.ino`.
4. Copy `firmware/EchoRobot/secrets.example.h` to `secrets.h`.
5. Add Wi-Fi credentials and a Gemini API key to `secrets.h`. Never commit that file.
6. Confirm your exact ESP32-S3 board and wire every device using `hardware/wiring.md`.
7. Set the GPIO pins in `config.h` to match your actual wiring.
8. Compile and upload. Start with the serial monitor at 115200 baud.

**Important:** The firmware is a hardware bring-up scaffold, not a finished end-to-end voice assistant. The audio capture/playback and Gemini audio request/response adapters are clearly marked integration points. Confirm the exact Gemini model and audio API flow for your Google AI Studio project before enabling them.

## Configuration

- `config.h`: GPIO pins, I2S settings, servo limits and audio buffer sizes.
- `secrets.h`: Wi-Fi SSID/password and Gemini API key (local only).
- `secrets.example.h`: safe template with placeholders.

## Security

- Never upload `secrets.h`, API keys, Wi-Fi passwords, or personal data.
- If a key was ever committed, revoke/rotate it in Google AI Studio and remove it from Git history.
- Use API restrictions and quotas where available.

## Testing checklist

- [ ] ESP32-S3 boots and prints its board/firmware status.
- [ ] Wi-Fi connects reliably.
- [ ] INMP441 is detected and produces non-zero audio samples.
- [ ] MAX98357A plays a local test tone at a safe volume.
- [ ] Each servo moves independently without resetting the ESP32.
- [ ] Gemini text request succeeds with a protected API key.
- [ ] Audio capture, request, response decoding and playback work end-to-end.
- [ ] Robot is tested from a separate power supply where required.
- [ ] README pin map and build steps match the final physical build.

## Hack Club submission evidence

Before submitting, add:
- Photos of the real robot (front, side, wiring and internals).
- A short demo video showing listening, response and servo movement.
- The exact board name and GPIO pin assignments.
- A bill of materials with actual part variants.
- A tested build log and any known limitations.

See [`docs/submission-checklist.md`](docs/submission-checklist.md).

## Contributing

This is an individual project. Suggestions and bug reports can be filed through GitHub Issues.

## License

MIT — see [`LICENSE`](LICENSE).

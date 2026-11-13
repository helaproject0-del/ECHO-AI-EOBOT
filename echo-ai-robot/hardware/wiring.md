# Wiring plan (verify before connecting)

The following is a **provisional signal map only**. GPIOs are examples from `config.h`, not confirmed project wiring. Replace them with the actual pin assignments.

| Module | Module pin | ESP32-S3 / supply |
|---|---|---|
| INMP441 | SCK / BCLK | GPIO 4 (provisional) |
| INMP441 | WS / LRCL | GPIO 5 (provisional) |
| INMP441 | SD | GPIO 6 (provisional) |
| INMP441 | VDD | Per breakout specification |
| INMP441 | GND | GND |
| MAX98357A | BCLK | GPIO 15 (provisional) |
| MAX98357A | LRC / LCK | GPIO 16 (provisional) |
| MAX98357A | DIN | GPIO 17 (provisional) |
| MAX98357A | VIN | Per breakout specification |
| MAX98357A | GND | Common GND |
| Head servo | Signal | GPIO 12 (provisional) |
| Arm servo | Signal | GPIO 13 (provisional) |
| Servos | V+ | Separate suitable regulated supply |
| Servos | GND | Supply GND + ESP32 common GND |

**Important:** Check whether your selected ESP32 Arduino core supports the chosen simultaneous I2S RX/TX configuration. The microphone and amplifier may need separate I2S peripherals or a shared bus configuration depending on the board/core. Never connect modules based only on this provisional table.

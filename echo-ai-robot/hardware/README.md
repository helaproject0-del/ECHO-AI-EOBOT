# Hardware

## Known project components

- ESP32-S3 development board
- INMP441 I2S microphone
- MAX98357A I2S amplifier
- Speaker (check impedance and power rating against the amplifier breakout)
- Two hobby servos
- Regulated power supply and common ground wiring

## Power warning

Do **not** assume the ESP32 3.3 V pin can power two servos or a speaker amplifier. Servos can draw large current spikes and reset or damage a board when powered incorrectly. Use a suitable regulated supply for the servos, connect grounds together, and follow the ratings of the exact modules. Do not connect a servo motor supply directly to an ESP32 GPIO.

## Before wiring

1. Identify the exact ESP32-S3 board and its pinout.
2. Check the INMP441 breakout voltage requirements and pin labels.
3. Check the MAX98357A breakout voltage and speaker requirements.
4. Confirm servo voltage/current requirements.
5. Choose GPIOs that are available on your board and supported by the selected I2S implementation.

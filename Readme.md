# TPMS application for [Flipper Zero](https://flipperzero.one/)
[![FlipC.org](https://flipc.org/wosk/flipperzero-tpms/badge)](https://flipc.org/wosk/flipperzero-tpms)

## Features
- Read [TPMS](https://en.wikipedia.org/wiki/Tire-pressure_monitoring_system) sensors
- Toggle 125 kHz relearn signal (manual on/off via Right button)

####  Supported sensors
* Schrader GG4
* Abarth 124 (soon)

## Relearn behavior (updated)

### What relearn does
The Relearn feature emits a raw 125 kHz LF (low-frequency) field using
`furi_hal_rfid_tim_read_start(125000, 0.5)`. Some TPMS sensors respond to an
LF field by entering a mode where they transmit their ID — this is the mechanism
used by OEM "relearn tools" to assign sensors to wheel positions.

**Important limitations:**
- This app emits a basic 125 kHz carrier and is **not** a fully compliant OEM
  relearn tool. It does **not** emulate the proprietary protocol or modulation
  used by Ford, GM, or other manufacturer-specific trigger tools.
- Compatibility with specific sensors (including Ford F-150 / Schrader OEM
  sensors) is not guaranteed. Results depend on the sensor type and its LF
  activation requirements.
- This is intended for experimentation and testing only.

### How to enable relearn
1. From the main menu, go to **Relearn** (via the start screen submenu).
2. Set **Relearn 125kHz** to **ON**.
3. Return to the **Read TPMS** (receiver) view.

### Using relearn in the receiver view

Two modes are available when **Relearn 125kHz** is **ON** in settings:

| Action | Result |
|---|---|
| Right short press | Toggle single fixed LF (125 kHz, 50% duty) ON/OFF |
| Right long press | Toggle **scan mode** — cycles through 4 LF configs automatically |
| Any press while active | Stops LF (both modes) |

**Single mode** (`LF ON` shown): emits a steady 125 kHz field at 50% duty cycle
until you press Right again or leave the view.

**Scan mode** (`LF SCAN 1/4` → `2/4` → … shown): automatically cycles through four
different 125 kHz configurations every 2 seconds, repeating indefinitely:

| Step | Frequency | Duty | Rationale |
|---|---|---|---|
| 1/4 | 125 kHz | 50% | Standard — most sensors |
| 2/4 | 125 kHz | 25% | Short pulse, lower field duty |
| 3/4 | 125 kHz | 75% | Longer pulse, stronger field |
| 4/4 | 125 kHz | 12.5% | Very short pulse (some OEM tools) |

Scan mode is useful when a single attempt fails — different sensors respond to
different pulse shapes. Keep the Flipper near the sensor and let it run through
all four before concluding the sensor did not respond.

If **Relearn 125kHz** is set to **OFF** in settings, the Right button does
nothing in the receiver view.

Leaving the receiver view always stops the LF field cleanly.

### Procedure for testing relearn on a 2019 Ford F-150 (or similar)
1. Enable Relearn in settings (see above).
2. Open **Read TPMS** receiver view.
3. Hold the Flipper Zero so its back (RFID antenna area) is close to the sensor
   valve or housing — similar to holding an RFID card.
4. **Long press Right** to start scan mode. Screen shows `LF SCAN 1/4`.
5. Hold steady while it cycles through all 4 steps (~8 seconds total per loop).
6. Watch the RSSI bar for signal activity — a spike means the sensor responded.
7. Press Right (short) to stop, or just leave the view.
8. If a sensor ID was received, it appears in the list. Press OK for details.
9. If no response, try moving the Flipper closer / repositioning near the valve.

### Previous behavior (changed)
- Previously, Right button always started a one-shot 3-second LF burst.
- The "Relearn 125kHz ON/OFF" setting had no effect on receiver behavior.
- Now: short press = single toggle, long press = auto-scan all configs.

## How to use (general)
In some circumstances TPMS sensors transmit messages periodically (car moving)
or by event (pressure drop, temperature spike), so they can be caught passively.

When sensor transmits, you will see jumps of the RSSI meter. If the sensor is
supported and the correct frequency/modulation is set, an item with Model and ID
will appear in the list.

Pressing OK displays temperature and pressure.

![input](tpms.gif)

## Building

### Using ufbt (recommended)
```
pip install ufbt
cd flipperzero-tpms
ufbt          # builds tpms.fap in dist/
```
Requires network access to download the Flipper Zero SDK on first run.

### Output
The compiled app is at: `dist/f7/tpms.fap`

Feel free to contribute via PR or report issues.

Code based on [weather station app](https://github.com/flipperdevices/flipperzero-good-faps/tree/dev/weather_station)

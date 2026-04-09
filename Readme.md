# TPMS application for [Flipper Zero](https://flipperzero.one/)
[![FlipC.org](https://flipc.org/wosk/flipperzero-tpms/badge)](https://flipc.org/wosk/flipperzero-tpms)

## Features
- Receive and decode supported [TPMS](https://en.wikipedia.org/wiki/Tire-pressure_monitoring_system) sensor packets
- Manual **125 kHz relearn test mode** for bench/vehicle experimentation
- Multiple selectable LF wake/test patterns (instead of one fixed pulse)

## Supported sensors
- Schrader GG4
- Abarth 124 (WIP)

## Relearn mode (experimental)
Relearn mode in this app is a **manual LF trigger helper** for testing. It is not a full OEM relearn tool emulation.

### Settings
From **Start -> Relearn**:
- **Relearn 125kHz**: `OFF` / `ON`
- **Pattern**:
  - `Continuous` (carrier only)
  - `Burst 100/100`
  - `Burst 250/250`
  - `Burst 500/100`
  - `Burst 100/500`
- **Runtime**: `Toggle`, `3s`, `5s`, `10s`
- **Duty**: `33%`, `50%`, `66%`

### Receiver controls
In the receiver screen:
- **Right button** starts LF output when Relearn is ON.
- If runtime is **Toggle**, Right starts/stops LF output.
- If runtime is timed (3s/5s/10s), Right starts the selected pattern for that duration.
- `LF ON <pattern>` is shown while LF is active.

This improves usability for testing scenarios (including trying 125 kHz activation timing variations on vehicles such as a 2019 Ford F-150), but does **not** guarantee compatibility with all sensors or OEM Ford relearn behavior.

## Build compatibility notes
This repo was minimally updated to match current external app build conventions and APIs used by latest Flipper firmware builds, while keeping the original app structure.

## Build
Use an up-to-date Flipper firmware tree and build as an external app (`fbt fap_tpms` or equivalent external app target).

## Demo
![input](tpms.gif)

Code based on [weather station app](https://github.com/flipperdevices/flipperzero-good-faps/tree/dev/weather_station)

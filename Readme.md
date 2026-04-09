# TPMS application for [Flipper Zero](https://flipperzero.one/)
[![FlipC.org](https://flipc.org/wosk/flipperzero-tpms/badge)](https://flipc.org/wosk/flipperzero-tpms)

## Features
- Read [TPMS](https://en.wikipedia.org/wiki/Tire-pressure_monitoring_system) sensors
- Manual 125 kHz relearn trigger for experimentation/testing

####  Supported sensors
* Schrader GG4
* Abarth 124 (soon)

## How to use
In some circumstances TPMS sensors should transmit message periodically (car moving) or by event (emergency pressure reduction or temperature increase), so it can be caught.

While the car is stationary or the sensor is not mounted in a tire, the app can emit a basic 125 kHz field for manual relearn testing. Enable **Relearn 125kHz** in the **Relearn** settings screen, then keep the sensor housing or valve near the back of the Flipper Zero and use the **Right** button in the receiver view to toggle the LF field on and off.

This makes LF testing less awkward than the previous short one-shot pulse, especially when experimenting with vehicles such as a 2019 Ford F-150.

This app still uses a basic `furi_hal_rfid_tim_read_start(125000, 0.5)` field. It does **not** guarantee compatibility with all TPMS sensors or OEM relearn procedures, and it should not be treated as a full emulation of a Ford/OEM trigger tool.

When sensor transmit message, you will see jumps of RSSI meter.
If sensor is supported and correct frequency and modulation was set, an item with Model and ID will be added for each sensor.

Pressing OK displays temperature and pressure.

![input](tpms.gif)

## Build notes

Build with the standard external-app flow:

```sh
ufbt
```

The generated sideloadable `.fap` is placed in the build output directory under `dist/` (for example `dist/f7-C/tpms.fap`, depending on the SDK/build layout).

Feel free to contribute via PR or report issue

Code based on [weather station app](https://github.com/flipperdevices/flipperzero-good-faps/tree/dev/weather_station)

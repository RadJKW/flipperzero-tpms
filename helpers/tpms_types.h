#pragma once

#include <furi.h>
#include <furi_hal.h>

#define TPMS_VERSION_APP "0.1"
#define TPMS_DEVELOPED "wosk"
#define TPMS_GITHUB "https://github.com/beewosk/flipperzero-tpms"

#define TPMS_KEY_FILE_VERSION 1
#define TPMS_KEY_FILE_TYPE "Flipper Tire Pressure Monitoring System Key File"

/** TPMSRxKeyState state */
typedef enum {
  TPMSRxKeyStateIDLE,
  TPMSRxKeyStateBack,
  TPMSRxKeyStateStart,
  TPMSRxKeyStateAddKey,
} TPMSRxKeyState;

/** TPMSHopperState state */
typedef enum {
  TPMSHopperStateOFF,
  TPMSHopperStateRunnig,
  TPMSHopperStatePause,
  TPMSHopperStateRSSITimeOut,
} TPMSHopperState;

typedef enum {
  TPMSLockOff,
  TPMSLockOn,
} TPMSLock;

typedef enum {
  TPMSViewVariableItemList,
  TPMSViewSubmenu,
  TPMSViewReceiver,
  TPMSViewReceiverInfo,
  TPMSViewWidget,
} TPMSView;

/** TPMSTxRx state */
typedef enum {
  TPMSTxRxStateIDLE,
  TPMSTxRxStateRx,
  TPMSTxRxStateTx,
  TPMSTxRxStateSleep,
} TPMSTxRxState;

typedef enum {
  TPMSRelearnOff,
  TPMSRelearnOn,
} TPMSRelearn;

typedef enum {
  TPMSRelearnPatternContinuous,
  TPMSRelearnPatternBurstFast100_100,
  TPMSRelearnPatternBurstSlow250_250,
  TPMSRelearnPatternBurstLongOn500_100,
  TPMSRelearnPatternBurstLongOff100_500,
} TPMSRelearnPattern;

typedef enum {
  TPMSRelearnRuntimeToggle,
  TPMSRelearnRuntime3s,
  TPMSRelearnRuntime5s,
  TPMSRelearnRuntime10s,
} TPMSRelearnRuntime;

typedef enum {
  TPMSRelearnDuty33,
  TPMSRelearnDuty50,
  TPMSRelearnDuty66,
} TPMSRelearnDuty;

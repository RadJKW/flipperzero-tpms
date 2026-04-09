# Build note

## What changed
- Updated relearn settings from a single ON/type toggle to preset-based LF test configuration.
- Added configurable pattern/runtime/duty options and runtime wiring into receiver behavior.
- Updated receiver Right-button behavior:
  - Relearn OFF => no LF start.
  - Toggle runtime => Right starts/stops LF.
  - Timed runtime => Right starts selected pattern for 3s/5s/10s.
- Added on-screen active indicator (`LF ON <pattern>`).
- Updated app metadata (`application.fam`) and README docs.

## Why no line-ending option
This app does not expose a text/serial export path where CR/LF framing applies. It emits LF field patterns and decodes RF packets internally, so line-ending configuration is not technically relevant and was intentionally not added.

## Build artifact path
This repo now builds directly with **uFBT** (latest public SDK channel). From repo root:

```bash
ufbt
```

Produced artifact:

```text
dist/tpms.fap
```

If you prefer building inside a full firmware tree, copy this app into
`applications_user/tpms/` and run `./fbt fap_tpms`, then collect:

```text
build/f7-firmware-D/.extapps/tpms.fap
```

## GitHub release artifacts
This repo now includes a release workflow (`.github/workflows/release.yml`) that:
- triggers on tags matching `v*` (and supports manual `workflow_dispatch`),
- builds with uFBT release SDK,
- publishes both `tpms.fap` and `tpms-<tag>.zip` to GitHub Releases.

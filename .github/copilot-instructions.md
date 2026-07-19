# OJOS-PRO

Arduino header-only library that drives a 128x64 SSD1306 OLED display to show
animated "eyes" (normal, angry, worried, relaxed, surprised, attentive,
winking). No build system, package manifest, or test suite exists in this
repo — it's included directly into an Arduino sketch via `#include <OJOS_PRO.h>`.
Validate changes by compiling an Arduino sketch that includes the header
(e.g. with `arduino-cli compile`), since there is no other way to catch
syntax errors.

## Dependencies

Relies on these Arduino libraries being installed alongside it: `Wire`,
`Adafruit_GFX`, `Adafruit_SSD1306`, `Arduino.h`.

## Architecture

- `OJOS_PRO.h` — single entry point. Defines macros aliasing every frame
  array (e.g. `OJOS_normales_00ARRAY` → `ojos_normales_00array`), then the
  `OJOS_PRO` class with one animation method per eye expression
  (`normales()`, `enojados()`, `preocupados()`, `relajados()`,
  `sorprendidos()`, `atentos()`, `guino()`, `ejemplo()`) plus `begin()`.
  It also instantiates a global `Adafruit_SSD1306 display` object
  (128x64, hardcoded I2C address `0x3C`).
- `arrays/*.hpp` — one file per expression (`normales`, `enojados`,
  `preocupados`, `relajados`, `sorprendidos`, `atentos`, `guino`). Each
  defines 20 `PROGMEM` bitmap frames named `ojos_<expression>_NNarray`
  (NN = `00`-`19`), one 128x64 monochrome bitmap per frame.

## Conventions

- Each animation method follows the same fixed pattern for every one of its
  20 frames: `display.clearDisplay()` → `display.drawBitmap(0, 0, <FRAME_MACRO>, 128, 64, 1)`
  → `display.display()` → `delay(100)`. When adding a new expression or
  frame, mirror this exact sequence and naming scheme.
- Frame arrays are always accessed through the `OJOS_<expression>_NNARRAY`
  macros defined at the top of `OJOS_PRO.h`, never via the raw
  `ojos_<expression>_NNarray` symbol names directly in animation methods.
- Naming and code comments are in Spanish (variable/method names, `//`
  comments); keep new additions consistent with this.
- `begin()` must be called from the sketch's `setup()` before any animation
  method is used — it initializes the display and halts (infinite loop) if
  `display.begin()` fails.

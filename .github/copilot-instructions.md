# OJOS-PRO

Arduino header-only library that drives a 128x64 SSD1306 OLED display to show
animated "eyes" (normal, angry, worried, relaxed, surprised, attentive,
winking). There is no package manifest or test suite in this repo; the
library is still included directly into Arduino sketches via
`#include <OJOS_PRO.h>`. For native validation of the portable animation logic,
use `make terminal` or `make run` to build and run the ASCII terminal preview
with plain host `g++`; this is the preferred way to check changes to the 7
portable animation methods without an Arduino toolchain or real hardware.
For Arduino-specific or hardware-only code paths such as `ejemplo()`, still
validate by compiling a real Arduino sketch (e.g. with `arduino-cli compile`).

## Dependencies

Relies on these Arduino libraries being installed alongside it: `Wire`,
`Adafruit_GFX`, `Adafruit_SSD1306`, `Arduino.h`.

## Architecture

- `OJOS_PRO.h` — single entry point for the eye-animation logic. It now
  depends on the `IEyeDisplay` abstraction instead of directly on
  `Adafruit_SSD1306`: the 7 portable animation methods (`normales()`,
  `enojados()`, `preocupados()`, `relajados()`, `sorprendidos()`,
  `atentos()`, `guino()`) render through an injected display backend, while
  `ejemplo()` remains hardware-only and is guarded by `#ifdef ARDUINO`.
  On Arduino builds it can still use an inline `SSD1306EyeDisplay` backend;
  on host builds it can use the terminal backend from `native/`.
- `include/IEyeDisplay.h` — abstract rendering interface (`begin()`,
  `clearDisplay()`, `drawBitmap(...)`, `display()`, `frameDelay(ms)`) that
  decouples the animation logic from any specific display implementation.
- `native/compat/Arduino.h` — minimal Arduino shim active when `ARDUINO` is
  not defined, allowing the same `OJOS_PRO.h` and `arrays/*.hpp` to compile
  with plain host `g++`.
- `native/TerminalEyeDisplay.h` / `native/TerminalEyeDisplay.cpp` — concrete
  ASCII terminal backend that renders frames to the console with ANSI
  clearing and optional step-by-step playback.
- `native/main.cpp` — interactive CLI for the terminal preview; it presents a
  numbered menu of expressions and playback modes.
- `Makefile` — host build entry point with `terminal`, `run`, and `clean`
  targets; it builds `bin/ojos_pro_terminal` and is not committed to git.
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
  comments) for the eye-animation domain logic (`OJOS_PRO.h` method bodies,
  `arrays/*.hpp`); keep new additions consistent with this. New generic
  infrastructure code (the `IEyeDisplay` interface, host-compat shim,
  terminal renderer, CLI, and Makefile) uses English naming/comments instead.
- `begin()` must be called from the sketch's `setup()` before any animation
  method is used — it initializes the display and halts (infinite loop) if
  `display.begin()` fails.
- `ejemplo()` is hardware-only and guarded by `#ifdef ARDUINO` because it uses
  Adafruit_GFX text/scrolling APIs with no terminal equivalent; it is not
  available through the native terminal CLI.

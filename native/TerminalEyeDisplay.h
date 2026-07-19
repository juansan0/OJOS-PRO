#ifndef TERMINAL_EYE_DISPLAY_H
#define TERMINAL_EYE_DISPLAY_H

#include "IEyeDisplay.h"

#include <cstdint>
#include <vector>

class TerminalEyeDisplay : public IEyeDisplay {
public:
    struct TerminalQuitRequested {};

    TerminalEyeDisplay();

    void begin() override;
    void clearDisplay() override;
    void drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, int16_t w, int16_t h, uint16_t color) override;
    void display() override;
    void frameDelay(unsigned long ms) override;

    void setStepMode(bool enabled);
    void setSpeedMultiplier(double multiplier);

private:
    enum {
        kWidth = 128,
        kHeight = 64
    };

    std::vector<uint8_t> _frameBuffer;
    bool _stepMode;
    double _speedMultiplier;
};

#endif

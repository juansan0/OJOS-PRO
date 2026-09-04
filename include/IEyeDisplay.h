#ifndef __IEYE_DISPLAY_h__
#define __IEYE_DISPLAY_h__

// Abstract interface for rendering eye animations to different backends,
// such as real SSD1306 hardware or an ASCII terminal renderer.

#include <cstdint>

class IEyeDisplay {
public:
    virtual ~IEyeDisplay() {}

    virtual void begin() = 0;
    virtual void clearDisplay() = 0;
    virtual void drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, int16_t w, int16_t h, uint16_t color) = 0;
    virtual void display() = 0;
    virtual void frameDelay(unsigned long ms) = 0;
};

#endif

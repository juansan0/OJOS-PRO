#include "TerminalEyeDisplay.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

TerminalEyeDisplay::TerminalEyeDisplay()
    : _frameBuffer(static_cast<size_t>(kWidth * kHeight), 0),
      _stepMode(false),
      _speedMultiplier(1.0) {
}

void TerminalEyeDisplay::begin() {
    clearDisplay();
}

void TerminalEyeDisplay::clearDisplay() {
    std::fill(_frameBuffer.begin(), _frameBuffer.end(), 0);
}

void TerminalEyeDisplay::drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, int16_t w, int16_t h, uint16_t color) {
    if (bitmap == nullptr || w <= 0 || h <= 0) {
        return;
    }

    const int16_t startX = std::max<int16_t>(0, x);
    const int16_t startY = std::max<int16_t>(0, y);
    const int16_t endX = std::min<int16_t>(kWidth, x + w);
    const int16_t endY = std::min<int16_t>(kHeight, y + h);

    const int16_t rowBytes = (w + 7) / 8;

    for (int16_t destY = startY; destY < endY; ++destY) {
        const int16_t srcY = destY - y;
        if (srcY < 0 || srcY >= h) {
            continue;
        }

        const uint8_t* rowStart = bitmap + (srcY * rowBytes);
        for (int16_t destX = startX; destX < endX; ++destX) {
            const int16_t srcX = destX - x;
            if (srcX < 0 || srcX >= w) {
                continue;
            }

            const int16_t byteIndex = srcX / 8;
            const int16_t bitIndex = 7 - (srcX % 8);
            const uint8_t sourceByte = rowStart[byteIndex];
            const uint8_t sourceBit = (sourceByte >> bitIndex) & 0x01u;

            if (color != 0 && sourceBit != 0) {
                _frameBuffer[static_cast<size_t>(destY * kWidth + destX)] = 1;
            }
        }
    }
}

void TerminalEyeDisplay::display() {
    std::cout << "\033[2J\033[H";

    // Render each logical pixel as two terminal cells (wide but compact) and
    // redraw the whole frame from the off-screen buffer on every update.
    for (int16_t y = 0; y < kHeight; ++y) {
        for (int16_t x = 0; x < kWidth; ++x) {
            const bool isOn = _frameBuffer[static_cast<size_t>(y * kWidth + x)] != 0;
            std::cout << (isOn ? "\u2588\u2588" : "  ");
        }
        std::cout << '\n';
    }

    std::cout.flush();
}

void TerminalEyeDisplay::frameDelay(unsigned long ms) {
    if (_stepMode) {
        std::cout << "-- press Enter for next frame (q + Enter to quit) --" << std::endl;
        std::string line;
        std::getline(std::cin, line);

        std::string trimmed = line;
        const std::string::size_type first = trimmed.find_first_not_of(" \t\r\n");
        if (first == std::string::npos) {
            trimmed.clear();
        } else {
            const std::string::size_type last = trimmed.find_last_not_of(" \t\r\n");
            trimmed = trimmed.substr(first, last - first + 1);
        }

        if (trimmed == "q" || trimmed == "Q") {
            throw TerminalQuitRequested();
        }
        return;
    }

    if (_speedMultiplier <= 0.0) {
        return;
    }

    const double delayMs = static_cast<double>(ms) * _speedMultiplier;
    if (delayMs <= 0.0) {
        return;
    }

    std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(delayMs));
}

void TerminalEyeDisplay::setStepMode(bool enabled) {
    _stepMode = enabled;
}

void TerminalEyeDisplay::setSpeedMultiplier(double multiplier) {
    _speedMultiplier = multiplier < 0.0 ? 0.0 : multiplier;
}

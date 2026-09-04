#ifndef OJOS_PRO_NATIVE_COMPAT_ARDUINO_H
#define OJOS_PRO_NATIVE_COMPAT_ARDUINO_H

#if !defined(ARDUINO)

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>

/*
 * Minimal Arduino compatibility definitions for host/native builds.
 * These shims provide just enough of the Arduino API surface for the
 * library's bitmap and string-literal helpers to compile outside of a real
 * Arduino toolchain.
 */

#ifndef PROGMEM
#define PROGMEM
#endif

#ifndef pgm_read_byte
#define pgm_read_byte(addr) (*(const uint8_t *)(addr))
#endif

#ifndef F
#define F(str) (str)
#endif

#ifndef ARDUINO_COMPAT_HAS_BYTE
typedef uint8_t byte;
#define ARDUINO_COMPAT_HAS_BYTE 1
#endif

class SerialClass {
public:
    template <typename T>
    void print(const T &value) {
        std::cout << value;
    }

    void print(const char *value) {
        std::cout << value;
    }

    void print(const std::string &value) {
        std::cout << value;
    }

    template <typename T>
    void println(const T &value) {
        std::cout << value << std::endl;
    }

    void println(const char *value) {
        std::cout << value << std::endl;
    }

    void println(const std::string &value) {
        std::cout << value << std::endl;
    }

    void println() {
        std::cout << std::endl;
    }
};

static SerialClass Serial;

inline void delay(unsigned long ms) {
    (void)ms;
}

#endif /* !defined(ARDUINO) */

#endif /* OJOS_PRO_NATIVE_COMPAT_ARDUINO_H */

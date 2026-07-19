#include "IEyeDisplay.h"
#include "TerminalEyeDisplay.h"
#include "OJOS_PRO.h"

#include <cctype>
#include <cstdlib>
#include <exception>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace {

struct AnimationEntry {
    int menuIndex;
    const char* name;
    void (OJOS_PRO::*method)();
};

int readIntWithPrompt(const std::string& prompt, int minValue, int maxValue) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);

        if (line.empty()) {
            std::cout << "Please enter a valid value." << std::endl;
            continue;
        }

        if (line.size() == 1 && (line[0] == 'q' || line[0] == 'Q')) {
            return 0;
        }

        try {
            const int value = std::stoi(line);
            if (value >= minValue && value <= maxValue) {
                return value;
            }
        } catch (const std::exception&) {
        }

        std::cout << "Please enter a valid value." << std::endl;
    }
}

int readPlaybackModeChoice(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);

        if (line.empty()) {
            return 1;
        }

        try {
            const int value = std::stoi(line);
            if (value == 1 || value == 2) {
                return value;
            }
        } catch (const std::exception&) {
        }

        std::cout << "Please enter 1 or 2, or press Enter for loop mode." << std::endl;
    }
}

bool readRepeatChoice(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);

        if (line.empty()) {
            return false;
        }

        const char first = static_cast<char>(std::tolower(static_cast<unsigned char>(line[0])));
        if (first == 'o') {
            return false;
        }
        if (first == 'r') {
            return true;
        }

        std::cout << "Please enter 'o' or 'r'." << std::endl;
    }
}

}  // namespace

int main() {
    std::cout << "OJOS-PRO Terminal Preview" << std::endl;
    std::cout << "Preview eye animations in the terminal without any hardware attached." << std::endl;

    TerminalEyeDisplay display;
    OJOS_PRO ojos(display);

    const std::vector<AnimationEntry> animations = {
        {1, "normales", &OJOS_PRO::normales},
        {2, "enojados", &OJOS_PRO::enojados},
        {3, "preocupados", &OJOS_PRO::preocupados},
        {4, "relajados", &OJOS_PRO::relajados},
        {5, "sorprendidos", &OJOS_PRO::sorprendidos},
        {6, "atentos", &OJOS_PRO::atentos},
        {7, "guino", &OJOS_PRO::guino},
    };

    bool began = false;

    while (true) {
        std::cout << std::endl;
        std::cout << "Choose an animation:" << std::endl;
        for (std::size_t i = 0; i < animations.size(); ++i) {
            const AnimationEntry& entry = animations[i];
            std::cout << entry.menuIndex << ") " << entry.name << std::endl;
        }
        std::cout << "0) quit (q also works)" << std::endl;

        const int selection = readIntWithPrompt("Pick an animation number: ", 0, 7);
        if (selection == 0) {
            std::cout << "Goodbye." << std::endl;
            return EXIT_SUCCESS;
        }

        const AnimationEntry& selectedAnimation = animations[static_cast<std::size_t>(selection - 1)];

        std::cout << "Playback mode:" << std::endl;
        std::cout << "1) Loop continuously" << std::endl;
        std::cout << "2) Step frame-by-frame" << std::endl;
        const int modeChoice = readPlaybackModeChoice("Pick a mode [1/2, Enter for loop]: ");
        const bool stepMode = (modeChoice == 2);

        display.setStepMode(stepMode);
        display.setSpeedMultiplier(1.0);

        if (!began) {
            ojos.begin();
            began = true;
        }

        try {
            if (!stepMode) {
                std::cout << "Play once or repeat until you press Ctrl+C?" << std::endl;
                const bool repeat = readRepeatChoice("(o = once [default], r = repeat): ");

                if (repeat) {
                    std::cout << "Repeating '" << selectedAnimation.name << "' animation — press Ctrl+C to stop." << std::endl;
                    while (true) {
                        (ojos.*(selectedAnimation.method))();
                    }
                }

                (ojos.*(selectedAnimation.method))();
                std::cout << "Done. Returning to menu." << std::endl;
            } else {
                (ojos.*(selectedAnimation.method))();
            }
        } catch (const TerminalEyeDisplay::TerminalQuitRequested&) {
            std::cout << "Playback stopped." << std::endl;
        }
    }
}

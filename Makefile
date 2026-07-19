# Simple build rules for the terminal-based eye renderer preview.

CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -O2
CPPFLAGS ?= -I. -Iinclude -Inative -Inative/compat
LDFLAGS ?=
LDLIBS ?= -pthread

BIN_DIR := bin
TARGET := $(BIN_DIR)/ojos_pro_terminal
SRCS := native/main.cpp native/TerminalEyeDisplay.cpp

.DEFAULT_GOAL := terminal

.PHONY: terminal clean run

all: terminal

$(BIN_DIR):
	mkdir -p $@

$(TARGET): $(SRCS) include/IEyeDisplay.h native/TerminalEyeDisplay.h native/compat/Arduino.h OJOS_PRO.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Built $(TARGET). Run with ./bin/ojos_pro_terminal"

terminal: $(TARGET)

clean:
	rm -rf $(BIN_DIR)

run: terminal
	./$(TARGET)

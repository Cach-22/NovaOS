# MNOS_POC Makefile for GitHub Codespaces

# Paths
DEVKITARM ?= /opt/devkitpro/devkitARM
INCLUDES = -I$(DEVKITARM)/include -I$(DEVKITARM)/include/3ds
LIBS = -lctru

# Source and output
SRC = source/main.cpp
OUT = build/MNOS_POC.3dsx

# Compiler
CXX = $(DEVKITARM)/bin/arm-none-eabi-g++
CXXFLAGS = -Wall -O2 -std=c++17 $(INCLUDES)

# Build rules
all: $(OUT)

$(OUT): $(SRC)
	mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC) $(LIBS)

clean:
	rm -rf build
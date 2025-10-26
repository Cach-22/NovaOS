TARGET = MNOS_POC
BUILD = build
SOURCE = source

$(BUILD)/$(TARGET).3dsx: $(SOURCE)/main.cpp
    @mkdir -p $(BUILD)
    $(DEVKITARM)/bin/arm-none-eabi-g++ -o $(BUILD)/$(TARGET).3dsx $(SOURCE)/main.cpp -lctru

all: $(BUILD)/$(TARGET).3dsx

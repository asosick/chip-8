#include <iostream>
#include <string>
#include "chip8/chip8.h"

int main() {
    Chip8 chip8;
    chip8.loadRom("CHIP-8/roms/rom.txt");
    return 0;
}

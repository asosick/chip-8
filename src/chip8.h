#ifndef CHIP_8_CHIP8_H
#define CHIP_8_CHIP8_H
#include "types.h"

const u16 START_ADDRESS = 0x200;
const u16 FONTSET_SIZE = 80;
const u16 FONTSET_START_ADDRESS = 0x50;

class Chip8{
public:
    u8  registers[16]{};
    u8  memory[4096]{};
    u16 index{};
    u16 pc{};
    u16 stack[16]{};
    u8  sp{};
    u8  delay_timer{};
    u8  sound_timer{};
    u8  keypad[16];
    u32 video[64 * 32]{};
    u16 opcode;

    Chip8();

    void loadRom(const std::string filename);

private:
    void loadFontSet();
};


u8 fontset[FONTSET_SIZE] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,       // 0
    0x20, 0x60, 0x20, 0x20, 0x70,       // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,   // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,   // 3
    0x90, 0x90, 0xF0, 0x10, 0x10,   // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

#endif //CHIP_8_CHIP8_H
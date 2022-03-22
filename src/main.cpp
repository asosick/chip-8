//#include "chip8/chip8.h"
#include "chip8_interpeter/Chip8_Rom_Interpreter.h"

int main() {
    //Chip8 chip8;
    convertBinToChip8Ops("/Users/asosick/dev/emulation/CHIP-8/roms/Breakout [Carmelo Cortez, 1979].ch8");
    //chip8.loadRom("CHIP-8/roms/rom.txt");
    return 0;
}

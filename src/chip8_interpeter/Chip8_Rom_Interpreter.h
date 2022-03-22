//
// Created by August Sosick on 2022-03-21.
//

#ifndef CHIP_8_CHIP8_ROM_INTERPRETER_H
#define CHIP_8_CHIP8_ROM_INTERPRETER_H
#include <vector>

void convertBinToChip8Ops(const char *const filename);

std::vector<uint8_t> parseHexVectorOfFile(const char *const filename);
#endif //CHIP_8_CHIP8_ROM_INTERPRETER_H

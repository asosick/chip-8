//
// Created by August Sosick on 2022-03-21.
//
#include <fstream>
#include "../types.h"
#include "Chip8_Rom_Interpreter.h"


void convertBinToChip8Ops(const char *const filename){
    std::vector<uint8_t> hex_file = parseHexVectorOfFile(filename);

}

std::vector<uint8_t> parseHexVectorOfFile(const char *const filename){
    std::ifstream input(filename, std::ios::binary);
    return std::vector<uint8_t>(std::istreambuf_iterator<char>(input), {});
}
//
// Created by August Sosick on 2022-03-21.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include "../types.h"
#include "Chip8_Rom_Interpreter.h"


void convertBinToChip8Ops(const char *const filename){
    std::vector<uint8_t> hex_file = parseHexVectorOfFile(filename);
    for(uint16_t i = 0; i < hex_file.size(); i+=2){
        uint16_t opcode = ((uint16_t)hex_file.at(i) << 8 ) | hex_file.at(i+1);
        std::cout << i + 400 << " | " << hexToOp(opcode) << "\n";
    }
}

std::string hexToOp(const uint16_t opcode){
    const uint16_t opcode_mask = 0xF000;
    std::ostringstream oss;
    switch(opcode & opcode_mask){
        case 0x0000:
            switch(opcode & 0x000F){
                case 0x0000:
                    return std::string("CLS");
                    break;
                case 0x000E:
                    return std::string("RET");
                    break;
            }
            break;
        case 0x1000:
            oss << "JP " << std::to_string(opcode & 0x0FFF);
            return std::string(oss.str());
            break;
        default:
            return std::string("Unknown op");
    }
}

std::vector<uint8_t> parseHexVectorOfFile(const char *const filename){
    std::ifstream input(filename, std::ios::binary);
    return std::vector<uint8_t>(std::istreambuf_iterator<char>(input), {});
}
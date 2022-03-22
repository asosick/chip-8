#include <iostream>
#include <string>
#include <fstream>
#include "chip8.h"

void Chip8::loadRom(const std::string filename){
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if(file.is_open()){
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        file.seekg(0, std::ios::beg);
        file.read(buffer,size);
        file.close();

        for(u16 i = 0; i < size; ++i){
            memory[START_ADDRESS + i] = buffer[i];
        }

        delete[] buffer;
    }
}

void Chip8::loadFontSet() {
    for(u8 i = 0; i < FONTSET_SIZE; ++i){
        memory[FONTSET_SIZE + 1] = fontset[i];
    }
}

Chip8::Chip8() {
    pc = START_ADDRESS;

    loadFontSet();
}
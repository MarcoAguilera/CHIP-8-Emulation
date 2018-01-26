//
//  chip8.hpp
//  CHIP-8
//
//  Created by Marco Aguilera on 1/16/18.
//  Copyright © 2018 Marco Aguilera. All rights reserved.
//

#ifndef chip8_hpp
#define chip8_hpp

#include <map>
using namespace std;

class Chip8{
public:
    Chip8();
    void initialize();
    void emulateCycle();
    
private:
    unsigned short opcode;
    unsigned char memory[4096]; // CHIP - 8 Has A Total of 4k Memory
    map<unsigned char, unsigned char> vRegisters;
    unsigned short iR; // Index Register
    unsigned short pC; // Program Counter
    unsigned char graphics[64 * 32]; // Screen Dimensions Are 64 * 32 (2048 Pixels)
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short stack[16];
    unsigned short stack_pointer;
    unsigned char key[16];
    // NOTE : STILL NEED TO FIGURE OUT HOW TO LOAD GAME INTO BUFFER
    unsigned char buffer[100];
    unsigned int bufferSize;
    
    // EACH ROW HAS HEXADECIMAL COORDINATES TO DRAW A DESIGNATED NUMBER OR LETTER
    unsigned char chip8_fontset[80]
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
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
    
};

#endif /* chip8_hpp */

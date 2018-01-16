//
//  chip8.hpp
//  CHIP-8
//
//  Created by Marco Aguilera on 1/16/18.
//  Copyright © 2018 Marco Aguilera. All rights reserved.
//

#ifndef chip8_hpp
#define chip8_hpp

class Chip8{
public:
    
private:
    unsigned short opcode;
    unsigned char memory[4096]; // CHIP - 8 Has A Total of 4k Memory
    unsigned char vRegisters[16]; // V - Registers (V0 - VE)
    unsigned short iR; // Index Register
    unsigned short pC; // Program Counter
};

#endif /* chip8_hpp */

//
//  chip8.cpp
//  CHIP-8
//
//  Created by Marco Aguilera on 1/16/18.
//  Copyright © 2018 Marco Aguilera. All rights reserved.
//

#include "chip8.hpp"

void Chip8::initialize()
{
    pC = 0x200;
    opcode = 0;
    iR = 0;
    stack_pointer = 0;
    
    // SDL_CLEAR *** NEEDS TO STILL BE DONE ***
    
    // CLEAR STACK
    for(unsigned i = 0; i < 16; i++)
    {
        stack[i] = 0;
    }
    
    // CLEAR V0 - VF REGISTERS
    for(unsigned i = 0; i < 16; i++)
    {
        vRegisters[i] = 0;
    }
    
    // CLEAR ALL MEMORY
    for(unsigned i = 0; i < 4096; i++)
    {
        memory[i] = 0;
    }
    
    // LOAD FONTSET
    for(unsigned i = 0; i < 80; i++)
    {
        memory[i] = chip8_fontset[i];
    }
    
    // RESET TIMERS *** NEEDS TO STILL BE DONE WITH SDL ***
    
    // LOAD GAME
    for(unsigned i = 0; i < bufferSize; i++)
    {
        memory[i + 512] = buffer[i];
    }
    
    
    
}
void Chip8::emulateCycle()
{
    
}

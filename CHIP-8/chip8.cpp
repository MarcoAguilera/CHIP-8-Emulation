//
//  chip8.cpp
//  CHIP-8
//
//  Created by Marco Aguilera on 1/16/18.
//  Copyright © 2018 Marco Aguilera. All rights reserved.
//

#include "chip8.hpp"
#include "iostream"

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
    opcode = memory[pC] << 8 | memory[pC + 1];
    
    switch(opcode & 0xF000){
        case 0x0000:
            switch(opcode & 0x000F){
                case 0x000:
                    cout << "SCREEN CLEARED\n";
                    pC += 2;
                    break;
                case 0x000E:
                    // STILL NEEDS TO BE FINISHED
                    // RETURN FROM SUBROUTINE
                    break;
                default:
                    cout << "ERROR!!\n";
                    break;
            }
        case 0x1000:
            pC = opcode & 0xF000;
            break;
        case 0x2000:
            stack[stack_pointer] = pC;
            pC = opcode & 0x0FFF;
            break;
        case 0x3000:
            if((vRegisters[(opcode >> 8) & (0x0F)]) == (opcode & 0x00FF)){
                pC += 4;
            }
            else{
                pC += 2;
            }
            break;
        case 0x4000:
            if((vRegisters[(opcode >> 8) & (0x0F)]) != (opcode & 0x00FF)){
                pC += 4;
            }
            else{
                pC += 2;
            }
            break;
        case 0x5000:
            if((vRegisters[(opcode >> 8) & (0x0F)]) == ((opcode >> 4) & 0x00F)){
                pC += 4;
            }
            else{
                pC += 2;
            }
            break;
        case 0x6000:
            vRegisters[(opcode >> 8) & 0x0F] = opcode & 0x00FF;
            break;
        case 0x7000:
            vRegisters[(opcode >> 8) & 0x0F] += opcode & 0x00FF;
            break;
        case 0x8000:
            switch(opcode &  0x000F){
                case 0x0:
                    
                    break;
                case 0x1:
                    break;
                case 0x2:
                    break;
                case 0x3:
                    break;
                case 0x4:
                    break;
                case 0x5:
                    break;
                case 0x6:
                    break;
                case 0x7:
                    break;
                case 0xE:
                    break;
                default:
                    cout << "ERROR!\n";
                    break;
            }
    }
}






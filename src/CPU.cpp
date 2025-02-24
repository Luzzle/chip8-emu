#include "include/CPU.h"

#include <iostream>
#include <cstdio>

#define ZeroMemory(dest,size) (memset(dest, 0, size))

// Thanks JamesGriffin for this fontset
unsigned char fontset[80] =
{
    0xF0, 0x90, 0x90, 0x90, 0xF0, //0
    0x20, 0x60, 0x20, 0x20, 0x70, //1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
    0x90, 0x90, 0xF0, 0x10, 0x10, //4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
    0xF0, 0x10, 0x20, 0x40, 0x40, //7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
    0xF0, 0x90, 0xF0, 0x90, 0x90, //A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
    0xF0, 0x80, 0x80, 0x80, 0xF0, //C
    0xE0, 0x90, 0x90, 0x90, 0xE0, //D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
    0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};

CPU::CPU(){
    // initialiser function
    pc = 0x200;
    i = 0x0;
    opcode = 0x0;

    // erase memory and display
    ZeroMemory(RAM, sizeof(RAM));
    ZeroMemory(gfx, sizeof(gfx));
    ZeroMemory(V, sizeof(V));

    stack = Stack();
    
    // load fontset into memory

    for (int i = 0; i < sizeof(fontset); i++){
        RAM[i] = fontset[i];
    }
}

void CPU::loadROM(char* path){
    FILE* p_file = fopen(path, "rb");

    if (!p_file){
        std::cerr << "Failed to open file " << path << std::endl;
        exit(-1);
    }

    // file size
    fseek(p_file, 0, SEEK_END);
    long file_size = ftell(p_file);
    rewind(p_file);

    BYTE* rom_buf = (BYTE*)malloc(file_size);

    if (rom_buf == NULL){
        std::cerr << "Failed to allocate space for rom buffer" << std::endl;
        exit(-1);
    }

    fread(rom_buf, sizeof(BYTE), file_size, p_file);
    
    // copy to ram
    if (file_size > 4096 - 0x200){
        std::cerr << "Rom size too big to fit in memory" << std::endl;
        exit(-1);
    }

    for (int i = 0; i < file_size; i++){
        RAM[0x200 + i] = (BYTE)rom_buf[i];
    }

    fclose(p_file);
    
    for (int i = 0; i <= 8; i+=2){
        printf("%.2x%.2x ", RAM[pc + i], RAM[pc + i + 1]);
    }

}
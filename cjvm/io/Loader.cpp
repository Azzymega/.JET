//
// Created by Danil on 23.08.2023.
//

#include "Loader.h"

#include <utility>
#include <iostream>

Loader::Loader(std::string Path) {
    this->Path = std::move(Path);
    loaded = 0;
}

void Loader::OpenStream() {
    this->Stream.open(Path,std::ios::binary);
    if (Stream.is_open()){
        std::cout << "Stream Opened" << std::endl;
        while (!Stream.eof()){
            uint8_t data;
            Stream >> data >> std::noskipws;
            Bytecode.push_back(data);
        }
    }
    else {
        std::cout << "Loader failed to load" << std::endl;
    }
}

void Loader::CloseStream() {
    this->Stream.close();
}

void Loader::LoadInTo(void* Dest, u4 Length) {
    memcpy(static_cast<char *>(Dest),&Bytecode[loaded],Length);
    loaded += Length;
}




//
// Created by Danil on 23.08.2023.
//

#include "Loader.h"

#include <utility>
#include <iostream>

Loader::Loader(std::string Path) {
    this->Path = std::move(Path);
}

void Loader::OpenStream() {
    this->Stream.open(Path,std::ios::binary);
    if (Stream.is_open()){
        std::cout << "Stream Opened" << std::endl;
    }
}

void Loader::CloseStream() {
    this->Stream.close();
}

void Loader::LoadInTo(void* Dest, u4 Length) {
    Stream.read(static_cast<char *>(Dest), Length);
}




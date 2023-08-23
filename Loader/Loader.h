//
// Created by Danil on 23.08.2023.
//

#ifndef JET_LOADER_H
#define JET_LOADER_H


#include <string>
#include <fstream>
#include "ConstantPool.h"
#include "../Core/Def.h"
#include "ClassFile.h"

class Loader {
public:
    explicit Loader(std::string Path);
    std::string Path;
    std::ifstream Stream;
    void OpenStream();
    void CloseStream();
    void LoadInTo(void *Dest,int Length);
    ConstantPool ParseConstantPool(uint16_t);

    ClassFile InitClassFile();
};


#endif //JET_LOADER_H

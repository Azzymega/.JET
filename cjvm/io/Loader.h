//
// Created by Danil on 23.08.2023.
//

#ifndef JET_LOADER_H
#define JET_LOADER_H


#include <string>
#include <fstream>
#include "../jvm_types/ConstantPool.h"
#include "../core/Def.h"
#include "../jvm_types/ClassFile.h"

class Loader {
public:
    explicit Loader(std::string Path);
    std::string Path;
    std::ifstream Stream;
    void OpenStream();
    void CloseStream();
    void LoadInTo(void *Dest, u4 Length);
};


#endif //JET_LOADER_H

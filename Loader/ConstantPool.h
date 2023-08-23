//
// Created by Danil on 23.08.2023.
//

#ifndef JET_CONSTANTPOOL_H
#define JET_CONSTANTPOOL_H


#include "CPInfo.h"

struct ConstantPool{
    int Index;
    ConstantPool* NextPool;
    CPInfo CCP;
};


#endif //JET_CONSTANTPOOL_H

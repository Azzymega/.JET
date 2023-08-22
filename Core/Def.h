//
// Created by Danil on 22.08.2023.
//

#ifndef JET_DEF_H
#define JET_DEF_H

#include <stdint.h>

typedef uint64_t AInteger;
typedef uint64_t Pointer;

#define VMStackSize 500
#define NativeStackSize 900

enum HeapTypes {
    Class,
    Interface,
    Array
};

enum PrimitiveTypes {
    Byte,
    Short,
    Int,
    Long,
    Char
};
#endif //JET_DEF_H

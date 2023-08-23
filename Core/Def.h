//
// Created by Danil on 22.08.2023.
//

#ifndef JET_DEF_H
#define JET_DEF_H

#include <stdint.h>

typedef uint64_t AInteger;
typedef uint64_t Pointer;

#define ThreadsLimit 100
#define VMStackSize 500
#define NativeStackSize 900
#define OperandStackSize 900

enum Types {
    Class,
    Interface,
    Array,
    Byte,
    Short,
    Int,
    Long,
    Char
};

enum ConstantPoolTypes {
    NameIndex,
    ClassIndex,
    NameAndTypeIndex,
    StringIndex,
    DescIndex,
    String
};
#endif //JET_DEF_H

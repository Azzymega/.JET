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

enum AccessFlags {
    ACC_PUBLIC = 0x0001,
    ACC_FINAL = 0x0010,
    ACC_SUPER = 0x0020,
    ACC_INTERFACE = 0x0200,
    ACC_ABSTRACT = 0x0400,
    ACC_SYNTHETIC = 0x1000,
    ACC_ANNOTATION = 0x2000,
    ACC_ENUM = 0x4000
};

enum ConstantPoolTags {
    CONSTANT_CLASS = 7,
    CONSTANT_FIELDREF = 9,
    CONSTANT_METHODREF = 10,
    CONSTANT_INTERFACEMETHODREF = 11,
    CONSTANT_STRING = 8,
    CONSTANT_INTEGER = 3,
    CONSTANT_FLOAT = 4,
    CONSTANT_LONG = 5,
    CONSTANT_DOUBLE = 6,
    CONSTANT_NAMEANDTYPE = 12,
    CONSTANT_UTF8 = 1,
    CONSTANT_METHODHANDLE = 15,
    CONSTANT_METHODTYPE = 16,
    CONSTANT_INVOKEDYNAMIC = 18
};

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

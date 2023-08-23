//
// Created by Danil on 23.08.2023.
//

#ifndef JET_CLASSFILE_H
#define JET_CLASSFILE_H

#include <vector>
#include "stdint.h"
#include "ConstantPool.h"
#include "../NonHeap/Field.h"

struct ClassFile {
    uint32_t RESERVED;
    uint16_t MinorVersion;
    uint16_t MajorVersion;
    uint16_t ConstantPoolAmount;
    ConstantPool Pool;
    uint16_t AccessFlags;
    uint16_t CurrentClass;
    uint16_t SuperClass;
    uint16_t InterfaceCount;
    std::vector<uint16_t> Interfaces;
    uint16_t FieldCount;
    std::vector<Field> Fields;
    uint16_t MethodCount;
    std::vector<Field> Methods;
    uint16_t AttributeCount;
    std::vector<Attribute> Attributes;
};
#endif //JET_CLASSFILE_H

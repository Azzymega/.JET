//
// Created by Danil on 23.08.2023.
//

#ifndef JET_CLASS_H
#define JET_CLASS_H

#include "ConstantPool.h"
#include "stdint.h"
#include "../Core/StringArray.h"
#include "FieldArray.h"

struct Class {
    struct ConstantPool Pool;
    wchar_t* Name;
    wchar_t* Super;
    int Flags;
    struct StringArray Interfaces;
    struct FieldArray Fields;
    struct FieldArray Methods;
    struct AttributeList Attributes;
};
#endif //JET_CLASS_H

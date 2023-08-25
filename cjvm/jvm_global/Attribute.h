//
// Created by Danil on 23.08.2023.
//

#ifndef JET_ATTRIBUTE_H
#define JET_ATTRIBUTE_H
#include "stdint.h"

struct Attribute {
    wchar_t* Name;
    int ByteArrayLength;
    int8_t* ByteArray;
};
#endif //JET_ATTRIBUTE_H

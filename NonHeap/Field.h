//
// Created by Danil on 23.08.2023.
//

#ifndef JET_FIELD_H
#define JET_FIELD_H
#include "stdint.h"
#include "AttributeList.h"

struct Field {
    int Flags;
    wchar_t* Name;
    wchar_t* Descriptor;
    struct AttributeList* AttributeList;
};
#endif //JET_FIELD_H

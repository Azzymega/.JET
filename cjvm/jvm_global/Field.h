//
// Created by Danil on 23.08.2023.
//

#ifndef JET_FIELD_H
#define JET_FIELD_H
#include "stdint.h"
#include "AttributeList.h"

struct Field {
    uint16_t Flags;
    uint16_t NameIndex;
    uint16_t DescriptorIndex;
    uint16_t AttributeIndex;
    struct AttributeList* AttributeList;
};
#endif //JET_FIELD_H

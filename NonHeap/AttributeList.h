//
// Created by Danil on 23.08.2023.
//

#ifndef JET_ATTRIBUTELIST_H
#define JET_ATTRIBUTELIST_H
#include "Attribute.h"
struct AttributeList {
    int Index;
    struct Attribute Attribute;
    struct AttributeList* NextElement;
};
#endif //JET_ATTRIBUTELIST_H

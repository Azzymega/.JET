//
// Created by Danil on 25.08.2023.
//

#ifndef JET_ENCLOSING_METHOD_ATTRIBUTE_H
#define JET_ENCLOSING_METHOD_ATTRIBUTE_H

#include "../../Core/Def.h"

struct enclosing_method_attribute {
    u2 class_index;
    u2 method_index;
};

#endif //JET_ENCLOSING_METHOD_ATTRIBUTE_H

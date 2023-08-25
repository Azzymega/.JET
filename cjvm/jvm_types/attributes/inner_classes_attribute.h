//
// Created by Danil on 25.08.2023.
//

#ifndef JET_INNER_CLASSES_ATTRIBUTE_H
#define JET_INNER_CLASSES_ATTRIBUTE_H

#include "../../Core/Def.h"
#include "../class.h"

struct inner_classes_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    struct class classes[max_class_number];
};

#endif //JET_INNER_CLASSES_ATTRIBUTE_H

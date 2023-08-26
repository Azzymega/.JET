//
// Created by Danil on 25.08.2023.
//

#ifndef JET_INNER_CLASSES_ATTRIBUTE_H
#define JET_INNER_CLASSES_ATTRIBUTE_H

#include "../../Core/Def.h"
#include "../class.h"

struct inner_classes_attribute {
    u2 number_of_classes;
    struct classT classes[max_class_number];
};

#endif //JET_INNER_CLASSES_ATTRIBUTE_H

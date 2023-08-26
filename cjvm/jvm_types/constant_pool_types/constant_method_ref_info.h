//
// Created by Danil on 26.08.2023.
//

#ifndef JET_CONSTANT_METHOD_REF_INFO_H
#define JET_CONSTANT_METHOD_REF_INFO_H

#include "../../core/Def.h"

struct constant_method_ref_info {
    u2 class_index;
    u2 name_and_type_index;
};
#endif //JET_CONSTANT_METHOD_REF_INFO_H

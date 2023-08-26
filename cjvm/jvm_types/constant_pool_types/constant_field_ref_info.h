//
// Created by Danil on 26.08.2023.
//

#ifndef JET_CONSTANT_FIELD_REF_INFO_H
#define JET_CONSTANT_FIELD_REF_INFO_H

#include "../../core/Def.h"

struct constant_field_ref_info {
    u2 class_index;
    u2 name_and_type_index;
};
#endif //JET_CONSTANT_FIELD_REF_INFO_H

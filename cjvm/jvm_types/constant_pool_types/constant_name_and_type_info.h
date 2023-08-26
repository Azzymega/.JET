//
// Created by Danil on 26.08.2023.
//

#ifndef JET_CONSTANT_NAME_AND_TYPE_INFO_H
#define JET_CONSTANT_NAME_AND_TYPE_INFO_H

#include "../../core/Def.h"

struct constant_name_and_type_info {
    u2 name_index;
    u2 descriptor_index;
};

#endif //JET_CONSTANT_NAME_AND_TYPE_INFO_H

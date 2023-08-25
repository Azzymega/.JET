//
// Created by Danil on 25.08.2023.
//

#ifndef JET_ATTRIBUTE_INFO_H
#define JET_ATTRIBUTE_INFO_H

#include "../../Core/Def.h"

struct attribute_info {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 info[max_attribute_length];
};

#endif //JET_ATTRIBUTE_INFO_H

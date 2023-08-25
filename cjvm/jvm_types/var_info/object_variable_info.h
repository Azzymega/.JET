//
// Created by Danil on 25.08.2023.
//

#ifndef JET_OBJECT_VARIABLE_INFO_H
#define JET_OBJECT_VARIABLE_INFO_H

#include "../../Core/Def.h"

struct object_variable_info {
    u1 tag = ITEM_Object;
    u2 cpool_index;
};

#endif //JET_OBJECT_VARIABLE_INFO_H

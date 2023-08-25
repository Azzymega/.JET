//
// Created by Danil on 25.08.2023.
//

#ifndef JET_UNINITIALIZEDTHIS_VARIABLE_INFO_H
#define JET_UNINITIALIZEDTHIS_VARIABLE_INFO_H

#include "../../Core/Def.h"

struct uninitializedthis_variable_info {
    u1 tag = ITEM_UninitializedThis;
};

#endif //JET_UNINITIALIZEDTHIS_VARIABLE_INFO_H

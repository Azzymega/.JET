//
// Created by Danil on 25.08.2023.
//

#ifndef JET_LOCAL_VARIABLE_TYPE_TABLE_H
#define JET_LOCAL_VARIABLE_TYPE_TABLE_H

#include "../core/Def.h"

struct local_variable_type_table {
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 signature_index;
    u2 index;
};

#endif //JET_LOCAL_VARIABLE_TYPE_TABLE_H

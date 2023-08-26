//
// Created by Danil on 25.08.2023.
//

#ifndef JET_LOCAL_VARIABLE_TYPE_TABLE_ATTRIBUTE_H
#define JET_LOCAL_VARIABLE_TYPE_TABLE_ATTRIBUTE_H

#include "../../core/Def.h"
#include "../local_variable_type_table.h"

struct local_variable_type_table_attribute {
    u2 local_variable_type_table_length;
    struct local_variable_type_table local_variable_type_table[max_local_variable_type_table_length];
};

#endif //JET_LOCAL_VARIABLE_TYPE_TABLE_ATTRIBUTE_H

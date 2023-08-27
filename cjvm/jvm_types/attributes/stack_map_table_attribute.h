//
// Created by Danil on 25.08.2023.
//

#ifndef JET_STACK_MAP_TABLE_ATTRIBUTE_H
#define JET_STACK_MAP_TABLE_ATTRIBUTE_H

#include "../../Core/Def.h"
#include "../stack_map_frame.h"

struct stack_map_table_attribute {
    u2 number_of_entries;
    struct stack_map_frame entries[max_entries];
};

#endif //JET_STACK_MAP_TABLE_ATTRIBUTE_H

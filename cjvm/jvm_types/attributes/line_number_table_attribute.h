//
// Created by Danil on 25.08.2023.
//

#ifndef JET_LINE_NUMBER_TABLE_ATTRIBUTE_H
#define JET_LINE_NUMBER_TABLE_ATTRIBUTE_H

#include "../../core/Def.h"
#include "../line_number_table.h"

struct line_number_table_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 line_number_table_length;
    struct line_number_table line_number_table[max_line_number_table_length];
};

#endif //JET_LINE_NUMBER_TABLE_ATTRIBUTE_H

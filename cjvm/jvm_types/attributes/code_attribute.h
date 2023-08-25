//
// Created by Danil on 25.08.2023.
//

#ifndef JET_CODE_ATTRIBUTE_H
#define JET_CODE_ATTRIBUTE_H

#include "../../Core/Def.h"
#include "../exceptions/exception_table.h"
#include "attribute_info.h"

struct code_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1 code[max_code_length];
    u2 exception_table_length;
    struct exception_table exception_table[max_exception_table_length];
    u2 attributes_count;
    struct attribute_info attributes[max_attribute_count];
};

#endif //JET_CODE_ATTRIBUTE_H

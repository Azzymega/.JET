//
// Created by Danil on 27.08.2023.
//

#ifndef JET_CODE_ATTRIBUTE_H
#define JET_CODE_ATTRIBUTE_H

#include <vector>
#include "../../core/Def.h"
#include "../exceptions/exception_table.h"
#include "attribute_info.h"

struct code_attribute {
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    std::vector<u1> code;
    u2 exception_table_length;
    std::vector<exception_table> exception_table;
    u2 attributes_count;
    std::vector<attribute_info*> attributes;
};

#endif //JET_CODE_ATTRIBUTE_H

//
// Created by Danil on 25.08.2023.
//

#ifndef JET_EXCEPTIONS_ATTRIBUTE_H
#define JET_EXCEPTIONS_ATTRIBUTE_H

#include "../../Core/Def.h"

struct exceptions_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_exceptions;
    u2 exception_index_table[max_number_of_exceptions];
};

#endif //JET_EXCEPTIONS_ATTRIBUTE_H

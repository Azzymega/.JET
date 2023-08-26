//
// Created by Danil on 25.08.2023.
//

#ifndef JET_ATTRIBUTE_INFO_H
#define JET_ATTRIBUTE_INFO_H

#include "code_attribute.h"
#include "enclosing_method_attribute.h"
#include "exceptions_attribute.h"
#include "inner_classes_attribute.h"
#include "line_number_table_attribute.h"
#include "local_variable_table_attribute.h"
#include "local_variable_type_table_attribute.h"
#include "signature_attribute.h"
#include "source_debug_extension_attribute.h"
#include "source_file_attribute.h"
#include "stack_map_table_attribute.h"
#include "synthetic_attribute.h"

struct attribute_info {
    u1 tag;
    u2 attribute_name_index;
    u4 attribute_length;
    union {
        code_attribute code_attribute;
        enclosing_method_attribute enclosing_method_attribute;
        exceptions_attribute exceptions_attribute;
        inner_classes_attribute inner_classes_attribute;
        line_number_table_attribute line_number_table_attribute;
        local_variable_table_attribute local_variable_table_attribute;
        local_variable_type_table_attribute local_variable_type_table_attribute;
        signature_attribute signature_attribute;
        source_debug_extension_attribute source_debug_extension_attribute;
        source_file_attribute source_file_attribute;
        stack_map_table_attribute stack_map_table_attribute;
        synthetic_attribute synthetic_attribute;
    };
};

#endif //JET_ATTRIBUTE_INFO_H

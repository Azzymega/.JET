//
// Created by Danil on 23.08.2023.
//

#ifndef JET_CPINFO_H
#define JET_CPINFO_H
#include <cstdint>
#include "../core/Def.h"
#include "constant_pool_types/constant_class_info.h"
#include "constant_pool_types/constant_double_info.h"
#include "constant_pool_types/constant_field_ref_info.h"
#include "constant_pool_types/constant_float_info.h"
#include "constant_pool_types/constant_integer_info.h"
#include "constant_pool_types/constant_interface_method_ref_info.h"
#include "constant_pool_types/constant_invoke_dynamic_info.h"
#include "constant_pool_types/constant_long_info.h"
#include "constant_pool_types/constant_method_handle_info.h"
#include "constant_pool_types/constant_method_type_info.h"
#include "constant_pool_types/constant_name_and_type_info.h"
#include "constant_pool_types/constant_string_info.h"
#include "constant_pool_types/constant_utf8_info.h"
#include "constant_pool_types/constant_method_ref_info.h"

struct CPInfo{
    ConstantPoolTags Tag;
    union {
        constant_class_info constant_class_info;
        constant_double_info constant_double_info;
        constant_field_ref_info constant_field_ref_info;
        constant_float_info constant_float_info;
        constant_integer_info constant_integer_info;
        constant_interface_method_ref_info constant_interface_method_ref_info;
        constant_invoke_dynamic_info constant_invoke_dynamic_info;
        constant_long_info constant_long_info;
        constant_method_handle_info constant_method_handle_info;
        constant_method_type_info constant_method_type_info;
        constant_method_ref_info constant_method_ref_info;
        constant_name_and_type_info constant_name_and_type_info;
        constant_string_info constant_string_info;
        constant_utf8_info constant_utf8_info;
    };
};


#endif //JET_CPINFO_H

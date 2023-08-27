//
// Created by Danil on 25.08.2023.
//

#ifndef JET_VERIFICATION_TYPE_INFO_H
#define JET_VERIFICATION_TYPE_INFO_H

#include "../../core/Def.h"
#include "top_variable_info.h"
#include "integer_variable_info.h"
#include "float_variable_info.h"
#include "long_variable_info.h"
#include "double_variable_info.h"
#include "null_variable_info.h"
#include "uninitializedthis_variable_info.h"
#include "object_variable_info.h"
#include "uninitialized_variable_info.h"

struct verification_type_info {
    enum item tag;
    union {
        struct top_variable_info top_variable_info;
        struct integer_variable_info integer_variable_info;
        struct float_variable_info float_variable_info;
        struct long_variable_info long_variable_info;
        struct double_variable_info double_variable_info;
        struct null_variable_info null_variable_info;
        struct uninitializedthis_variable_info uninitializedThis_variable_info;
        struct object_variable_info object_variable_info;
        struct uninitialized_variable_info uninitialized_variable_info;
    };

};
#endif //JET_VERIFICATION_TYPE_INFO_H

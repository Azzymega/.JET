//
// Created by Danil on 25.08.2023.
//

#ifndef JET_SOURCE_DEBUG_EXTENSION_ATTRIBUTE_H
#define JET_SOURCE_DEBUG_EXTENSION_ATTRIBUTE_H

#include "../../core/Def.h"

struct source_debug_extension_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 debug_extension[max_debug_extension];
};

#endif //JET_SOURCE_DEBUG_EXTENSION_ATTRIBUTE_H

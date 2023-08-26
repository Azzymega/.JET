//
// Created by Danil on 25.08.2023.
//

#ifndef JET_FIELD_INFO_H
#define JET_FIELD_INFO_H

#include "../core/Def.h"
#include "attributes/attribute_info.h"

struct field_info {
    u2 access_flags{};
    u2 name_index{};
    u2 descriptor_index{};
    u2 attributes_count{};
    struct attribute_info attributes[max_attribute_count];
};

#endif //JET_FIELD_INFO_H

//
// Created by Danil on 25.08.2023.
//

#ifndef JET_SIGNATURE_ATTRIBUTE_H
#define JET_SIGNATURE_ATTRIBUTE_H

#include "../../Core/Def.h"

struct signature_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 signature_index;
};

#endif //JET_SIGNATURE_ATTRIBUTE_H

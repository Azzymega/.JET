//
// Created by Danil on 25.08.2023.
//

#ifndef JET_CLASS_H
#define JET_CLASS_H

#include "../Core/Def.h"

struct class {
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags16;
};

#endif //JET_CLASS_H

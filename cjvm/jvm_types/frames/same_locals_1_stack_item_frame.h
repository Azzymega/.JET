//
// Created by Danil on 25.08.2023.
//

#ifndef JET_SAME_LOCALS_1_STACK_ITEM_FRAME_H
#define JET_SAME_LOCALS_1_STACK_ITEM_FRAME_H

#include "../var_info/verification_type_info.h"

struct same_locals_1_stack_item_frame {
    struct verification_type_info stack[1];
};

#endif //JET_SAME_LOCALS_1_STACK_ITEM_FRAME_H

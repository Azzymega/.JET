//
// Created by Danil on 25.08.2023.
//

#ifndef JET_SAME_LOCALS_1_STACK_ITEM_FRAME_EXTENDED_H
#define JET_SAME_LOCALS_1_STACK_ITEM_FRAME_EXTENDED_H
#include "../../Core/Def.h"
#include "../var_info/verification_type_info.h"

struct same_locals_1_stack_item_frame_extended {
    u1 frame_type = frame_tags::SAMEL1SIFE_SE;
    u2 offset_delta;
    verification_type_info stack[1];
};

#endif //JET_SAME_LOCALS_1_STACK_ITEM_FRAME_EXTENDED_H

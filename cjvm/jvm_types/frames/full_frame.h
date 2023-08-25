//
// Created by Danil on 25.08.2023.
//

#ifndef JET_FULL_FRAME_H
#define JET_FULL_FRAME_H

#include "../var_info/verification_type_info.h"

struct full_frame {
    u1 frame_type;
    u2 offset_delta;
    u2 number_of_locals;
    verification_type_info locals[max_locals_count];
    u2 number_of_stack_items;
    verification_type_info stack[max_stack_count];
};

#endif //JET_FULL_FRAME_H

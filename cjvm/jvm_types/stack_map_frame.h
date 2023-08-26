//
// Created by Danil on 25.08.2023.
//

#ifndef JET_STACK_MAP_FRAME_H
#define JET_STACK_MAP_FRAME_H

#include "frames/same_frame.h"
#include "frames/same_locals_1_stack_item_frame.h"
#include "frames/same_locals_1_stack_item_frame_extended.h"
#include "frames/chop_frame.h"
#include "frames/same_frame_extended.h"
#include "frames/append_frame.h"
#include "frames/full_frame.h"

struct stack_map_frame {
    u1 frame_type{};
    union {
        same_frame same_frame;
        same_locals_1_stack_item_frame same_locals_1_stack_item_frame;
        same_locals_1_stack_item_frame_extended same_locals_1_stack_item_frame_extended;
        chop_frame chop_frame{};
        same_frame_extended same_frame_extended;
        append_frame append_frame;
        full_frame full_frame;
    };
};

#endif //JET_STACK_MAP_FRAME_H

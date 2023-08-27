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
    u1 frame_type;
    union {
        struct same_frame same_frame;
        struct same_locals_1_stack_item_frame same_locals_1_stack_item_frame;
        struct same_locals_1_stack_item_frame_extended same_locals_1_stack_item_frame_extended;
        struct chop_frame chop_frame;
        struct same_frame_extended same_frame_extended;
        struct append_frame append_frame;
        struct full_frame full_frame;
    };
};

#endif //JET_STACK_MAP_FRAME_H

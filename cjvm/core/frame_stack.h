//
// Created by Danil on 27.08.2023.
//

#ifndef JET_FRAME_STACK_H
#define JET_FRAME_STACK_H

#include "../jvm_frames/frame.h"
#include <stack>

struct frame_stack {
    std::stack<frame> frame;
};


#endif //JET_FRAME_STACK_H

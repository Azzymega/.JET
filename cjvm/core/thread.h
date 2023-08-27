//
// Created by Danil on 27.08.2023.
//

#ifndef JET_THREAD_H
#define JET_THREAD_H


#include "Def.h"
#include "native_stack.h"
#include "frame_stack.h"

struct thread {
    u4 program_counter;
    native_stack n_stack;
    frame_stack f_stack;
};


#endif //JET_THREAD_H

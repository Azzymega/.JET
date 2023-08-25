//
// Created by Danil on 22.08.2023.
//

#ifndef JET_THREAD_H
#define JET_THREAD_H

#include "Def.h"
#include "../jvm_frames/FrameStack.h"
#include "NativeStack.h"

struct Thread {
    AInteger ProgramCounter;
    struct FrameStack Stack;
    struct NativeStack NStack;
};
#endif //JET_THREAD_H

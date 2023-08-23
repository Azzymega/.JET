//
// Created by Danil on 22.08.2023.
//

#ifndef JET_THREADSTACK_H
#define JET_THREADSTACK_H
#include "../Frames/Frame.h"
#include "ThreadStack.h"
#include "Def.h"

struct ThreadStack {
    AInteger StackSize;
    struct Frame Data[VMStackSize];
};

#endif //JET_THREADSTACK_H

//
// Created by Danil on 23.08.2023.
//

#ifndef JET_JET_H
#define JET_JET_H

#include "ThreadStack.h"
#include "NativeStack.h"
#include "Thread.h"

struct JET {
    struct Thread ThreadsArray[ThreadsLimit];
};
#endif //JET_JET_H

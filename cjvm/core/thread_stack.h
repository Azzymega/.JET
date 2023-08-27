//
// Created by Danil on 27.08.2023.
//

#ifndef JET_THREAD_STACK_H
#define JET_THREAD_STACK_H


#include <stack>
#include "thread.h"

struct thread_stack {
    std::stack<thread> stack;
};


#endif //JET_THREAD_STACK_H

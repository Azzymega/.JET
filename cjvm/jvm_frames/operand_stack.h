//
// Created by Danil on 27.08.2023.
//

#ifndef JET_OPERAND_STACK_H
#define JET_OPERAND_STACK_H

#include <stack>
#include "local_mut.h"

struct operand_stack {
    std::stack<local_mut> stack;
};


#endif //JET_OPERAND_STACK_H

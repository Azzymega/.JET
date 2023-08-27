//
// Created by Danil on 27.08.2023.
//

#ifndef JET_FRAME_H
#define JET_FRAME_H


#include "../core/Def.h"
#include "operand_stack.h"
#include "operand_locals.h"

struct frame {
    u4 return_value{};
    operand_stack stack;
    operand_locals locals;
    u2 const_pool_reference{};
};


#endif //JET_FRAME_H

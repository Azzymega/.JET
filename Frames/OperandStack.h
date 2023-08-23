//
// Created by Danil on 23.08.2023.
//

#ifndef JET_OPERANDSTACK_H
#define JET_OPERANDSTACK_H

#include "LCTypes.h"

struct OperandStack {
    int StackSize;
    struct LCTypes Array[OperandStackSize];
};
#endif //JET_OPERANDSTACK_H

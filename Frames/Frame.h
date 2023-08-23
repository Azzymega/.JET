//
// Created by Danil on 22.08.2023.
//

#ifndef JET_FRAME_H
#define JET_FRAME_H

#include "LCVariablesList.h"
#include "OperandStack.h"
#include "../NonHeap/ConstantPool.h"

struct Frame {
    struct LCTypes ReturnValue;
    int LCLength;
    struct LCVariableList* Locals;
    struct OperandStack OperandStack;
    struct ConstantPool* CurrentClassConstantPoolReference;
};
#endif //JET_FRAME_H

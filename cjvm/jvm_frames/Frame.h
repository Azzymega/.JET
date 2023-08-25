//
// Created by Danil on 22.08.2023.
//

#ifndef JET_FRAME_H
#define JET_FRAME_H

#include "LCVariablesList.h"
#include "OperandStack.h"
#include "../jvm_global/Class.h"

struct Frame {
    struct LCTypes ReturnValue;
    int InstructionPointer;
    int LCLength;
    struct LCVariableList* Locals;
    struct OperandStack OperandStack;
    struct Class* CurrentClass;
};
#endif //JET_FRAME_H

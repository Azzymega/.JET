//
// Created by Danil on 22.08.2023.
//

#include "NativeStack.h"

void NativePushToStack(struct NativeStack* Stack, int8_t Data){
    Stack->Data[Stack->StackSize] = Data;
    Stack->StackSize++;
}

void NativePopFromStack(struct NativeStack* Stack){
    Stack->Data[Stack->StackSize] = 0;
    Stack->StackSize--;
}
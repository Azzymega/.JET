//
// Created by Danil on 22.08.2023.
//

#include "ThreadStack.h"

void ThreadPushToStack(struct ThreadStack* Stack, struct Frame Frame){
    Stack->Data[Stack->StackSize] = Frame;
    Stack->StackSize++;
}

void ThreadPopFromStack(struct ThreadStack* Stack){
    Stack->StackSize--;
}
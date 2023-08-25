//
// Created by Danil on 22.08.2023.
//

#ifndef JET_NATIVESTACK_H
#define JET_NATIVESTACK_H
#include "stdint.h"
#include "Def.h"

struct NativeStack {
    AInteger StackSize;
    int8_t Data[NativeStackSize];
};
#endif //JET_NATIVESTACK_H

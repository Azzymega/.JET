//
// Created by Danil on 22.08.2023.
//

#ifndef JET_HEAP_H
#define JET_HEAP_H

#include "HeapChunk.h"

struct Heap {
    AInteger AllocationNumber;
    struct HeapChunk* Chunk;
};
#endif //JET_HEAP_H

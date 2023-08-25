//
// Created by Danil on 22.08.2023.
//

#ifndef JET_HEAPCHUNK_H
#define JET_HEAPCHUNK_H

#include "../../core/Def.h"

struct HeapChunk {
    struct HeapChunck* NextChunk;
    AInteger ChunkSize;
    enum Types CurrentType;
    Pointer* Data;
};
#endif //JET_HEAPCHUNK_H

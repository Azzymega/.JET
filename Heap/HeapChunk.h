//
// Created by Danil on 22.08.2023.
//

#ifndef JET_HEAPCHUNK_H
#define JET_HEAPCHUNK_H

#include "../Core/Def.h"

struct HeapChunk {
    struct HeapChunck* NextChunk;
    AInteger ChunkSize;
    enum HeapTypes CurrentType;
    Pointer* Data;
};
#endif //JET_HEAPCHUNK_H

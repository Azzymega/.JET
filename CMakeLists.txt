cmake_minimum_required(VERSION 3.25)
project(JET)
set(CMAKE_CXX_FLAGS -static-libgcc)
set(CMAKE_CXX_FLAGS -static-libstdc++)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_STANDARD 17)
set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_executable(JET main.cpp Core/Thread.c Core/Thread.h Core/Def.h Core/ThreadStack.c Core/ThreadStack.h
        TS/PrimitiveTypes/IntegerTypes/Byte.c TS/PrimitiveTypes/IntegerTypes/Byte.h
        TS/PrimitiveTypes/IntegerTypes/Short.c TS/PrimitiveTypes/IntegerTypes/Short.h
        TS/PrimitiveTypes/IntegerTypes/Int.c TS/PrimitiveTypes/IntegerTypes/Int.h TS/PrimitiveTypes/IntegerTypes/Long.c
        TS/PrimitiveTypes/IntegerTypes/Long.h TS/PrimitiveTypes/IntegerTypes/Char.c
        TS/PrimitiveTypes/IntegerTypes/Char.h TS/PrimitiveTypes/FloatingTypes/Float.c
        TS/PrimitiveTypes/FloatingTypes/Float.h TS/PrimitiveTypes/FloatingTypes/Double.c
        TS/PrimitiveTypes/FloatingTypes/Double.h TS/PrimitiveTypes/IntegerTypes/Boolean.c
        TS/PrimitiveTypes/IntegerTypes/Boolean.h TS/PrimitiveTypes/IntegerTypes/ReturnAddress.c
        TS/PrimitiveTypes/IntegerTypes/ReturnAddress.h TS/ReferenceTypes/ClassType.c TS/ReferenceTypes/ClassType.h
        TS/ReferenceTypes/ArrayType.c TS/ReferenceTypes/ArrayType.h TS/ReferenceTypes/InterfaceType.c
        TS/ReferenceTypes/InterfaceType.h Core/Frame.c Core/Frame.h Core/NativeStack.c Core/NativeStack.h
        Heap/Heap.c Heap/Heap.h Heap/HeapChunk.c Heap/HeapChunk.h NonHeap/PermanentGeneration.cpp
        NonHeap/PermanentGeneration.h NonHeap/PermanentGeneration.cpp NonHeap/MethodArea.cpp NonHeap/MethodArea.h NonHeap/Object.cpp NonHeap/Object.h NonHeap/ConstantPool.cpp NonHeap/ConstantPool.h)

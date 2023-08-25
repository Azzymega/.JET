//
// Created by Danil on 23.08.2023.
//

#ifndef JET_LCTYPES_H
#define JET_LCTYPES_H

#include "../Core/Def.h"
#include "../jvm_types/primitive_types/FloatingTypes/Double.h"
#include "../jvm_types/primitive_types/FloatingTypes/Float.h"
#include "../jvm_types/primitive_types/IntegerTypes/Boolean.h"
#include "../jvm_types/primitive_types/IntegerTypes/Byte.h"
#include "../jvm_types/primitive_types/IntegerTypes/Char.h"
#include "../jvm_types/primitive_types/IntegerTypes/Long.h"
#include "../jvm_types/primitive_types/IntegerTypes/Int.h"
#include "../jvm_types/reference_types/ArrayType.h"
#include "../jvm_types/primitive_types/IntegerTypes/ReturnAddress.h"
#include "../jvm_types/reference_types/ClassType.h"
#include "../jvm_types/reference_types/InterfaceType.h"


struct LCTypes {
    int Index;
    enum Types Type;
    union {
        struct Double Double;
        struct Float Float;
        struct Boolean Boolean;
        struct Byte Byte;
        struct Char Char;
        struct Int Int;
        struct Long Long;
        struct ReturnAddress ReturnAddress;
        struct ArrayType ArrayType;
        struct ClassType ClassType;
        struct InterfaceType InterfaceType;
    };
};
#endif //JET_LCTYPES_H

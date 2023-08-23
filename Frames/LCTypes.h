//
// Created by Danil on 23.08.2023.
//

#ifndef JET_LCTYPES_H
#define JET_LCTYPES_H

#include "../Core/Def.h"
#include "../TS/PrimitiveTypes/FloatingTypes/Double.h"
#include "../TS/PrimitiveTypes/FloatingTypes/Float.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Boolean.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Byte.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Char.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Int.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Long.h"
#include "../TS/PrimitiveTypes/IntegerTypes/ReturnAddress.h"
#include "../TS/ReferenceTypes/ArrayType.h"
#include "../TS/ReferenceTypes/ClassType.h"
#include "../TS/ReferenceTypes/InterfaceType.h"

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

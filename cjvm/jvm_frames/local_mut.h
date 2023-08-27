//
// Created by Danil on 27.08.2023.
//

#ifndef JET_LOCAL_MUT_H
#define JET_LOCAL_MUT_H

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


struct local_mut {
    int Index;
    Types Type;
    union {
        Double Double;
        Float Float;
        Boolean Boolean;
        struct Byte Byte;
        struct Char Char;
        struct Int Int;
        struct Long Long;
        ReturnAddress ReturnAddress;
        ArrayType ArrayType;
        ClassType ClassType;
        InterfaceType InterfaceType;
    };
};


#endif //JET_LOCAL_MUT_H

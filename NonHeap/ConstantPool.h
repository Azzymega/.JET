//
// Created by Danil on 22.08.2023.
//

#ifndef JET_CONSTANTPOOL_H
#define JET_CONSTANTPOOL_H


#include <vector>
#include <string>
#include "../TS/PrimitiveTypes/FloatingTypes/Double.h"
#include "../TS/PrimitiveTypes/FloatingTypes/Float.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Boolean.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Byte.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Char.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Int.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Long.h"
#include "../TS/PrimitiveTypes/IntegerTypes/ReturnAddress.h"
#include "../TS/PrimitiveTypes/IntegerTypes/Short.h"
#include "../TS/ReferenceTypes/ArrayType.h"
#include "../TS/ReferenceTypes/ClassType.h"
#include "../TS/ReferenceTypes/InterfaceType.h"

class ConstantPool {
private:
    std::vector<std::wstring> StringConstants;
    std::vector<Double> DoubleConstants;
    std::vector<Float> FloatConstants;
    std::vector<Boolean> BooleanConstants;
    std::vector<Byte> ByteConstants;
    std::vector<Char> CharConstants;
    std::vector<Int> IntConstants;
    std::vector<Long> LongConstants;
    std::vector<ReturnAddress> ReturnAddressConstants;
    std::vector<Short> ShortConstants;
    std::vector<ArrayType> ArrayPointerConstants;
    std::vector<ClassType> ClassPointerConstants;
    std::vector<InterfaceType> InterfacePointerConstants;
};


#endif //JET_CONSTANTPOOL_H

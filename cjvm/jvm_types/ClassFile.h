//
// Created by Danil on 23.08.2023.
//

#ifndef JET_CLASSFILE_H
#define JET_CLASSFILE_H

#include <vector>
#include <cstdint>
#include "ConstantPool.h"
#include "../jvm_global/Field.h"
#include "field_info.h"
#include "method_info.h"

struct ClassFile {
    u4 magic;
    u2 MinorVersion;
    u2 MajorVersion;
    u2 ConstantPoolAmount;
    CPInfo constant_pool[300];
    u2 AccessFlags16;
    u2 CurrentClass;
    u2 SuperClass;
    u2 InterfaceCount;
    u2 interfaces[max_interfaces_count];
    u2 FieldCount;
    field_info fields[max_field_count];
    u2 MethodCount;
    method_info methods[max_methods_count];
    u2 AttributeCount;
    attribute_info attributes[max_attribute_count];
};

#endif //JET_CLASSFILE_H


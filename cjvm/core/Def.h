//
// Created by Danil on 22.08.2023.
//

#ifndef JET_DEF_H
#define JET_DEF_H

#include <stdint.h>

typedef uint64_t AInteger;
typedef uint64_t Pointer;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint8_t u1;
typedef int16_t nu2;
typedef int32_t nu4;
typedef int8_t nu1;

enum frame_tags {
    SAME_S = 0,
    SAME_E = 63,
    SAMEL1SI_S = 64,
    SAMEL1SI_E = 127,
    SAMEL1SIFE_SE = 247,
    CHOP_S = 248,
    CHOP_E = 250,
    SAME_FE = 251,
    APPENDF_S = 252,
    APPENDF_E = 254,
    FULLF_SE = 255
};

enum attributes {
    constant_value,
    code,
    stack_map_table,
    exceptions,
    inner_classes,
    enclosing_method,
    synthetic,
    signature,
    source_file,
    source_debug_extension,
    line_number_table,
    local_variable_table,
    local_variable_type_table,
    deprecated,
    runtime_visible_annotations,
    runtime_invisible_annotations,
    runtime_visible_parameter_annotations,
    runtime_invisible_parameter_annotations,
    annotation_default,
    bootstrap_method
};

enum item {
    ITEM_Top = 0,
    ITEM_Integer = 1,
    ITEM_Float = 2,
    ITEM_Long = 4,
    ITEM_Double = 3,
    ITEM_Null = 5,
    ITEM_UninitializedThis = 6,
    ITEM_Object = 7,
    ITEM_Uninitialized = 8
};

enum AccessFlags {
    ACC_PUBLIC = 0x0001,
    ACC_FINAL = 0x0010,
    ACC_SUPER = 0x0020,
    ACC_INTERFACE = 0x0200,
    ACC_ABSTRACT = 0x0400,
    ACC_SYNTHETIC = 0x1000,
    ACC_ANNOTATION = 0x2000,
    ACC_ENUM = 0x4000
};

enum ConstantPoolTags {
    CONSTANT_CLASS = 7,
    CONSTANT_FIELDREF = 9,
    CONSTANT_METHODREF = 10,
    CONSTANT_INTERFACEMETHODREF = 11,
    CONSTANT_STRING = 8,
    CONSTANT_INTEGER = 3,
    CONSTANT_FLOAT = 4,
    CONSTANT_LONG = 5,
    CONSTANT_DOUBLE = 6,
    CONSTANT_NAMEANDTYPE = 12,
    CONSTANT_UTF8 = 1,
    CONSTANT_METHODHANDLE = 15,
    CONSTANT_METHODTYPE = 16,
    CONSTANT_INVOKEDYNAMIC = 18
};

enum Types {
    Class,
    Interface,
    Array,
    Byte,
    Short,
    Int,
    Long,
    Char
};

enum ConstantPoolTypes {
    NameIndex,
    ClassIndex,
    NameAndTypeIndex,
    StringIndex,
    DescIndex,
    String
};
#endif //JET_DEF_H

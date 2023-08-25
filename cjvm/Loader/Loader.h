//
// Created by Danil on 23.08.2023.
//

#ifndef JET_LOADER_H
#define JET_LOADER_H


#include <string>
#include <fstream>
#include "ConstantPool.h"
#include "../Core/Def.h"
#include "../jvm_types/ClassFile.h"

class Loader {
public:
    explicit Loader(std::string Path);
    std::string Path;
    std::ifstream Stream;
    void OpenStream();
    void CloseStream();
    attribute_info parse_attribute();
    u2 parse_interface();
    u2 parse_flags();
    u2 parse_super_class();
    u2 parse_interface_count();
    u2 parse_attribute_count();
    u2 parse_current_class();
    u2 parse_method_count();
    void parse_interfaces(ClassFile* file);
    u2 parse_field_count();
    field_info parse_field();
    method_info parse_method();
    ClassFile * InitClassFile();
    void LoadInTo(void *Dest, u4 Length);
    ConstantPool ParseConstantPool(uint16_t *CPUnits);
};


#endif //JET_LOADER_H

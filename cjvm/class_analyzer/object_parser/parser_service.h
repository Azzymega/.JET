//
// Created by Danil on 26.08.2023.
//

#ifndef JET_PARSER_SERVICE_H
#define JET_PARSER_SERVICE_H


#include <cstdint>
#include "../../jvm_types/ConstantPool.h"
#include "../../io/Loader.h"
#include "../../core/Def.h"
#include "../../jvm_types/CPInfo.h"
#include "../../io/Loader.h"
#include "../../jvm_types/attributes/attribute_info.h"

class parser_service {
public:
    ClassFile * InitClassFile(Loader* loader);
private:
    stack_map_frame parse_frame(Loader* loader);
    attributes return_attribute_tag(std::string name);
    exception_table parse_table(Loader* loader);
    std::string* parse_string(u2 size,Loader* loader);
    uint16_t set_pool_amount(uint16_t wanted_size);
    ConstantPool parse_pool(uint16_t *length, Loader *loader);
    u2 parse_interface(Loader* loader);
    u2 parse_flags(Loader* loader);
    u2 parse_super_class(Loader* loader);
    u2 parse_interface_count(Loader* loader);
    u2 parse_attribute_count(Loader* loader);
    u2 parse_current_class(Loader* loader);
    u2 parse_method_count(Loader* loader);
    u2 parse_field_count(Loader* loader);
    void parse_interfaces(ClassFile *file, Loader *loader);
    attribute_info *parse_attribute(Loader *loader, CPInfo *pool);
    field_info parse_field(Loader *loader, CPInfo *pool);
    method_info parse_method(Loader *loader, CPInfo *pool);
};


#endif //JET_PARSER_SERVICE_H

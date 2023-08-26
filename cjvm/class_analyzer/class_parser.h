//
// Created by Danil on 26.08.2023.
//

#ifndef JET_CLASS_PARSER_H
#define JET_CLASS_PARSER_H


#include "../jvm_types/ClassFile.h"
#include "../io/Loader.h"
#include "object_parser/parser_service.h"

class class_parser {
private:
    parser_service service;
public:
    ClassFile* parse_file(Loader* loader);
};


#endif //JET_CLASS_PARSER_H

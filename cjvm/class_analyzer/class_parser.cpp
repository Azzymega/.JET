//
// Created by Danil on 26.08.2023.
//

#include "class_parser.h"

ClassFile* class_parser::parse_file(Loader *loader) {
    return service.InitClassFile(loader);
}

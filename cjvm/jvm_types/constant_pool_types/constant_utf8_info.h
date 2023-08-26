//
// Created by Danil on 26.08.2023.
//

#ifndef JET_CONSTANT_UTF8_INFO_H
#define JET_CONSTANT_UTF8_INFO_H

#include <string>
#include "../../core/Def.h"

struct constant_utf8_info {
    u2 length;
    std::string* string;
};

#endif //JET_CONSTANT_UTF8_INFO_H

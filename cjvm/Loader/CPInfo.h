//
// Created by Danil on 23.08.2023.
//

#ifndef JET_CPINFO_H
#define JET_CPINFO_H
#include <cstdint>
#include "../Core/Def.h"

struct CPInfo{
    ConstantPoolTags Tag;
    u4 Size;
    uint8_t* Data;
};


#endif //JET_CPINFO_H

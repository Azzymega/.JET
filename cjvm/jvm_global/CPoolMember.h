//
// Created by Danil on 23.08.2023.
//

#ifndef JET_CPOOLMEMBER_H
#define JET_CPOOLMEMBER_H

#include "../Core/Def.h"

struct CPoolMember {
    int Index;
    enum ConstantPoolTypes Type;
    union {
        int NameIndex;
        int ClassIndex;
        int NameAndTypeIndex;
        int StringIndex;
        int DescIndex;
        wchar_t* String;
    };
};
#endif //JET_CPOOLMEMBER_H

//
// Created by Danil on 23.08.2023.
//

#ifndef JET_LCVARIABLESLIST_H
#define JET_LCVARIABLESLIST_H

#include "LCTypes.h"

struct LCVariableList {
    int Index;
    struct LCTypes* NextType;
};
#endif //JET_LCVARIABLESLIST_H

//
// Created by Danil on 23.08.2023.
//

#ifndef JET_STRINGARRAY_H
#define JET_STRINGARRAY_H
#include "stdint.h"

struct StringArray {
    int Index;
    wchar_t* String;
    struct StringArray* NextElement;
};
#endif //JET_STRINGARRAY_H

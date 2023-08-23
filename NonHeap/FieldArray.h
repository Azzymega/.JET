//
// Created by Danil on 23.08.2023.
//

#ifndef JET_FIELDARRAY_H
#define JET_FIELDARRAY_H

#include "Field.h"

struct FieldArray {
    int Index;
    struct Field* Field;
    struct FieldArray* NextField;
};
#endif //JET_FIELDARRAY_H

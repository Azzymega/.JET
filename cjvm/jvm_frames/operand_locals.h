//
// Created by Danil on 27.08.2023.
//

#ifndef JET_OPERAND_LOCALS_H
#define JET_OPERAND_LOCALS_H


#include <vector>
#include "local_mut.h"

struct operand_locals {
    std::vector<local_mut> locals;
};


#endif //JET_OPERAND_LOCALS_H

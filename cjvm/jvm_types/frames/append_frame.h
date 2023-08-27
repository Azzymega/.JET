//
// Created by Danil on 25.08.2023.
//

#ifndef JET_APPEND_FRAME_H
#define JET_APPEND_FRAME_H

#include "../../Core/Def.h"
#include "../var_info/verification_type_info.h"

struct append_frame {
    u2 offset_delta;
    struct verification_type_info locals[3];
};

#endif //JET_APPEND_FRAME_H

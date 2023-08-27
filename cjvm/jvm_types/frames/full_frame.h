//
// Created by Danil on 27.08.2023.
//

#ifndef JET_FULL_FRAME_H
#define JET_FULL_FRAME_H


struct full_frame {
    u2 offset_delta;
    u2 number_of_locals;
    std::vector<verification_type_info> locals;
    u2 number_of_stack_items;
    std::vector<verification_type_info> stack;
};


#endif //JET_FULL_FRAME_H

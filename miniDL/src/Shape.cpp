//
// Created by Frank on 2019-12-17.
//

#include "Shape.h"
#include "Tools.h"

namespace MiniDL{
    Shape::Shape(){

    }

    Shape::~Shape(){

    }

    int Shape::get_dim(const int index){
        do_assert(index >= 0 && index < data.size(), "index is invalidate.");
    }
}

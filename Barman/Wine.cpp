//
// Created by ohrf02 on 8/20/2017.
//

#include "Wine.h"
#include <sstream>

const char* Wine::getName() const {
    std::ostringstream string;
    string << Name << " (" << year << ")";
    return string.str().c_str();
}

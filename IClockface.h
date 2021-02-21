#pragma once

#include "DateTime.hpp"

class IClockface {

    virtual void setup() = 0;
    virtual void update() = 0;
};

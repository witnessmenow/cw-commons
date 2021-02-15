#ifndef IClockface_h
#define IClockface_h

#include "DateTime.hpp"

class IClockface {

    virtual void setup() = 0;
    virtual void update() = 0;
};

#endif
#ifndef COURSEWORK_WRITABLE_H
#define COURSEWORK_WRITABLE_H

#include "ValidationException.h"

class Writable {
public:
    virtual void write(ofstream &stream) = 0;
};

#endif //COURSEWORK_WRITABLE_H

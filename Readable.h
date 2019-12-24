#ifndef COURSEWORK_READABLE_H
#define COURSEWORK_READABLE_H

#include "ValidationException.h"

class Readable {
public:
    virtual void read(ifstream &stream) = 0;
};

#endif //COURSEWORK_READABLE_H

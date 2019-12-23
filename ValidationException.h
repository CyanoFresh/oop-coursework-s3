#ifndef COURSEWORK_VALIDATIONEXCEPTION_H
#define COURSEWORK_VALIDATIONEXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

class ValidationException : public invalid_argument {
public:
    explicit ValidationException(const char *what) : invalid_argument(what) {}
};


#endif //COURSEWORK_VALIDATIONEXCEPTION_H

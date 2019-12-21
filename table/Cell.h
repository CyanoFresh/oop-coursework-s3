#ifndef COURSEWORK_CELL_H
#define COURSEWORK_CELL_H


#include "Object.h"

#include <string>
#include <iostream>

namespace ATable {
    class Cell : public Object {
    private:
        unsigned int width;
    public:
        Cell();

        ~Cell();

        virtual string output() = 0;

        void print(ostream &stream);

        void setWidth(unsigned int width);

        unsigned int getWidth();

    private:
        string boundary(string value);
    };
}

#endif //COURSEWORK_CELL_H

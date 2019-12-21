#ifndef COURSEWORK_APPEAR_H
#define COURSEWORK_APPEAR_H


#include "Object.h"

#include <iostream>

namespace ATable {
    class Appearance : public Object {
    public:
        char left_top_corner;
        char right_top_corner;
        char left_bottom_corner;
        char right_bottom_corner;

        char vertical_line;
        char horizontal_line;

        char left_separator;
        char right_separator;
        char top_separator;
        char bottom_separator;

        char center_separator;
    public:
        Appearance();

        ~Appearance();

        void print(ostream &stream);

        friend ostream &operator<<(ostream &stream, Appearance obj);

        friend ostream &operator<<(ostream &stream, Appearance *obj);
    };
}

#endif //COURSEWORK_APPEAR_H

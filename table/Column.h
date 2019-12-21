#ifndef COURSEWORK_COLUMN_H
#define COURSEWORK_COLUMN_H

#include "Object.h"
#include "Cell.h"
#include "TableExceptions.h"

namespace ATable {
    class Column : public Object {
    public:
        unsigned int width;
    public:
        Column(unsigned int width);

        ~Column();

        unsigned int getWidth();

        void setWidth(unsigned int width);

        virtual Cell *getCell(int id) = 0;
    };
}

#endif //COURSEWORK_COLUMN_H

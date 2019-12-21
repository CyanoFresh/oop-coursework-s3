#ifndef COURSEWORK_SC_H
#define COURSEWORK_SC_H


#include "Cell.h"
#include "Column.h"

#include <vector>


namespace ATable {
    class SimpleColumn : public Column {
    public:
        string name;
    protected:
        vector<Cell *> *cells;
    public:
        SimpleColumn(string name, unsigned int width);

        ~SimpleColumn();

        string getName();

        void setName(string name);

        void addCell(Cell *cell);

        Cell *getCell(int id);

        unsigned int getHeight();
    };
}

#endif //COURSEWORK_SC_H

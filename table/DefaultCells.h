#pragma once

#include <cmath>
#include "Cell.h"

namespace ATable {
    class StringCell : public Cell {
    public:
        string value;
    public:
        StringCell(string value) {
            this->value = value;
        }

        string output() {
            return this->value;
        }
    };

    class IntegerCell : public Cell {
    public:
        int value;
    public:
        IntegerCell(int value) {
            this->value = value;
        }

        string output() {
            return to_string(this->value);
        }
    };

    class LongCell : public Cell {
    public:
        int value;
    public:
        LongCell(int value) {
            this->value = value;
        }

        string output() {
            return to_string(this->value);
        }
    };

    class FloatCell : public Cell {
    public:
        float value;
        int percision;
    public:
        FloatCell(float value, int percision) {
            this->value = value;
            this->percision = percision;
        }

        FloatCell(float value) : FloatCell(value, 3) {}

        string output() {
            string integer = to_string((int) value);
            string fractional = to_string((int) (abs(value - (int) value) * pow(10, percision)));
            string result;
            result += integer + "." + fractional;
            return result;
        }
    };

    class DoubleCell : public Cell {
    public:
        float value;
        int percision;
    public:
        DoubleCell(double value, int percision) {
            this->value = value;
            this->percision = percision;
        }

        DoubleCell(double value) : DoubleCell(value, 3) {}

        string output() {
            string integer = to_string((int) value);
            string fractional = to_string((int) (abs(value - (int) value) * pow(10, percision)));
            string result;
            result += integer + "." + fractional;
            return result;
        }
    };

}

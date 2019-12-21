#include "Cell.h"

namespace ATable {
	Cell::Cell() {
		this->width = 0;
	}


	Cell::~Cell() {
	}

	void Cell::print(ostream& stream) {
		stream << this->boundary(this->output());
	}

	void Cell::setWidth(unsigned int width) {
		this->width = width;
	}

	unsigned int Cell::getWidth() {
		return this->width;
	}

	string Cell::boundary(string value) {
		if (value.length() < this->width) {
			return value + string(this->width - value.length(), ' ');
		}
		if (value.length() > this->width) {
			string temp = value;
			temp.resize(this->width);
			return temp;
		}
		return value;
	}
}
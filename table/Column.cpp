#include "Column.h"


namespace ATable {
	Column::Column(unsigned int width) {
		this->width = width;
	}
	Column::~Column() {
	}
	unsigned int Column::getWidth() {
		return this->width;
	}
	void Column::setWidth(unsigned int width) {
		this->width = width;
	}
}

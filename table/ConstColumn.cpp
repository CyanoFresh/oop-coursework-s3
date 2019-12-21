#include "ConstColumn.h"


namespace ATable {
	ConstColumn::ConstColumn(string value) : Column(value.length()){
		this->cell = new StringCell(value);
		this->cell->setWidth(this->getWidth());
	}

	ConstColumn::~ConstColumn() {
		delete cell;
	}
	Cell* ConstColumn::getCell(int id) {
		return this->cell;
	}
}


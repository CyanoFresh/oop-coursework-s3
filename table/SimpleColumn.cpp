#include "SimpleColumn.h"


namespace ATable {
	SimpleColumn::SimpleColumn(string name, unsigned int widht) : Column(width) {
		this->width = widht;
		this->name = name;
		this->cells = new vector<Cell*>();
	}

	SimpleColumn::~SimpleColumn() {
		for (unsigned int i = 0; i < this->cells->size(); i++) {
			delete this->getCell(i);
		}
		delete this->cells;
	}

	string SimpleColumn::getName() {
		return this->name;
	}

	void SimpleColumn::setName(string name) {
		this->name = name;
	}

	void SimpleColumn::addCell(Cell* cell) {
		cell->setWidth(this->width);
		this->cells->push_back(cell);
	}
	Cell* SimpleColumn::getCell(int id) {
		if (id >= this->cells->size()) {
			return NULL;
		}
		Cell* cell = (*(this->cells))[id];
		return cell;
	}

	unsigned int SimpleColumn::getHeight() {
		return this->cells->size();
	}
}

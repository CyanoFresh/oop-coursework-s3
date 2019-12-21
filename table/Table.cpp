#include "Table.h"

namespace ATable {
	Table::Table(Appearance preset, string name) {
		this->preset = preset;
		this->name = name;
		this->columns = new vector<Column*>();
	}

	Table::~Table() {
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			Column* temp = this->getColumn(col);
			delete temp;
		}
		delete this->columns;
	}

	void Table::addColumn(Column* column) {
		this->columns->push_back(column);
	}

	void Table::addCell(int column, Cell* cell) {
		SimpleColumn* scolumn = dynamic_cast<SimpleColumn*>(this->getColumn(column));
		if (scolumn) {
			scolumn->addCell(cell);
		}
	}

	void Table::print(ostream & stream) {
		try {
			//Top line
			this->drawLine(stream, this->preset.left_top_corner, this->preset.horizontal_line, this->preset.top_separator, this->preset.right_top_corner);

			//Output headers			
			this->drawColumnsHeaders(stream, this->preset.vertical_line);
			this->drawLine(stream, this->preset.left_separator, this->preset.horizontal_line, this->preset.center_separator, this->preset.right_separator);
			
			//Rows
			unsigned int maxRowHeight = this->getMaxRowHeight();
			for (int row = 0; row < maxRowHeight; row++) {
				this->drawRow(stream, row, this->preset.vertical_line);
				if (row < maxRowHeight - 1) {
					this->drawLine(stream, this->preset.left_separator, this->preset.horizontal_line, this->preset.center_separator, this->preset.right_separator);
				}
			}
			//Bottom line
			this->drawLine(stream, this->preset.left_bottom_corner, this->preset.horizontal_line, this->preset.bottom_separator, this->preset.right_bottom_corner);

		}
		catch (exception e) {
			stream << "Unable to print table [" << this->name << "]" << endl;
		}
	}


	Column* Table::getColumn(int id) {
		if (!(id < this->columns->size())) {
			throw new WrongIDException();
		}
		return (*(this->columns))[id];
	}

	void Table::drawLine(ostream& stream, char left_corner, char horizontal_line, char center_separator, char right_corner) {
		stream << left_corner;
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			stream << string(this->getColumn(col)->getWidth(), horizontal_line);
			if (col < this->columns->size() - 1) {
				stream << center_separator;
			}
		}
		stream << right_corner << endl;
	}

	void Table::drawRow(ostream& stream, unsigned int row, char vertical_line) {
		stream << vertical_line;
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			Cell* cell = this->getColumn(col)->getCell(row);
			if (cell) {
				cell->print(stream);
			}
			else {
				stream << string(this->getColumn(col)->getWidth(), ' ');
			}
			stream << vertical_line;
		}
		stream << endl;
	}

	void Table::drawColumnsHeaders(ostream& stream, char vertical_line) {
		stream << vertical_line;
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			Column* column = this->getColumn(col);
			SimpleColumn* scolumn = dynamic_cast<SimpleColumn*>(column);
			if (scolumn) {
				stream << boundary(scolumn->getName(), scolumn->getWidth());
			}
			else {
				stream << string(column->getWidth(),' ');
			}
			stream << vertical_line;
		}
		stream << endl;
	}

	unsigned int Table::getMaxRowHeight() {
		unsigned int maxHeight = 0;
		for (int i = 0; i < this->columns->size(); i++) {
			SimpleColumn* scolumn =	dynamic_cast<SimpleColumn*>(this->getColumn(i));
			if (scolumn) {
				unsigned int temp = scolumn->getHeight();
				if (maxHeight < temp) {
					maxHeight = temp;
				}
			}
		}
		return maxHeight;
	}

	string Table::boundary(string value, int width) {
		if (value.length() < width) {
			return value + string(width - value.length(), ' ');
		}
		if (value.length() > width) {
			string temp = value;
			temp.resize(width);
			return temp;
		}
		return value;

	}

	

}

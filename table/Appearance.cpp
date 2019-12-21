#include "Appearance.h"


namespace ATable {
	Appearance::Appearance() {
		this->left_top_corner = ' ';
		this->right_top_corner = ' ';
		this->left_bottom_corner = ' ';
		this->right_bottom_corner = ' ';
		this->vertical_line = ' ';
		this->horizontal_line = ' ';
		this->left_separator = ' ';
		this->right_separator = ' ';
		this->top_separator = ' ';
		this->bottom_separator = ' ';
		this->center_separator = ' ';
	}


	Appearance::~Appearance() {
	}
	void Appearance::print(ostream& stream) {
		stream << "left_top_corner: " << left_top_corner << endl;
		stream << "right_top_corner: " << right_top_corner << endl;
		stream << "left_bottom_corner: " << left_bottom_corner << endl;
		stream << "right_bottom_corner: " << right_bottom_corner << endl;
		stream << "vertical_line: " << vertical_line << endl;
		stream << "horizontal_line: " << horizontal_line << endl;
		stream << "left_separator: " << left_separator << endl;
		stream << "right_separator: " << right_separator << endl;
		stream << "top_separator: " << top_separator << endl;
		stream << "bottom_separator: " << bottom_separator << endl;
		stream << "center_separator: " << center_separator << endl;

	}

	ostream& operator<<(ostream& stream, Appearance obj)
	{
		obj.print(stream);
		return stream;
	}

	ostream& operator<<(ostream& stream, Appearance* obj) {
		return operator<<(stream, *obj);
	}

}

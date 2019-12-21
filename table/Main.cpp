#include <iostream>
#include "ATable.h"

using namespace std;

int main() {
	ATable::Table* table = new ATable::Table(ATable::DefaultAppearance(), "Test table"); // creating a new table with default borders

	table->addColumn(new ATable::SimpleColumn("type", 20)); // creating column with different cells adding ability with name "type" ans width: 20
	table->addColumn(new ATable::ConstColumn("-->")); // creating column with NO ability of field difference
	table->addColumn(new ATable::SimpleColumn("fields", 30)); // creating column with different cells adding ability with name "fields" ans width: 30

	table->addCell(0, new ATable::StringCell("String cell example")); // adding to column with id: 0 a new string cell with text: "String cell example"
	table->addCell(2, new ATable::StringCell("Hello darkness my old friend")); // adding to column with id: 2 a new string cell with text: "Hello darkness my old friend"

	table->addCell(0, new ATable::StringCell("Integer cell example")); // adding to column with id: 0 a new string cell with text: "Integer cell example"
	table->addCell(2, new ATable::IntegerCell(228)); // adding to column with id: 2 a new integer cell with value: 228

	table->addCell(0, new ATable::StringCell("Float cell example")); // adding to column with id: 0 a new string cell with text: "Float cell example"
	table->addCell(2, new ATable::FloatCell(1488.228)); // adding to column with id: 2 a new float cell with value: 1488.228

	table->print(cout); //printing the table to cout stream

	delete table; // deleting table
}


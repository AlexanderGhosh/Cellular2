#include "Cell.h"

Cell::Cell() : type_(CellType::Air) {

}

Cell::Cell(CellType type) : Cell() {
	type_ = type;
}
const CellType Cell::getType() const
{
	return type_;
}

void Cell::setType(CellType type)
{
	type_ = type;
}

Cell::operator bool()
{
	return type_ == CellType::Air;
}

Cell::operator bool() const
{
	return type_ == CellType::Air;
}
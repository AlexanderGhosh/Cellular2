#pragma once
#include "CellTypes.h"

class Cell
{
public:
	Cell();
	Cell(CellType type);
	~Cell() = default;

	const CellType getType() const;
	void setType(CellType type);

	operator bool();
	operator bool() const;
private:
	CellType type_;
};


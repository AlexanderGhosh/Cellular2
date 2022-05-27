#include "Grid.h"
#include "Cell.h"
#include "CellTypes.h"
#include <iostream>

Grid::Grid() :useX_(true), dataX_(nullptr), dataY_(nullptr), width_(0), height_(0), area_(0)
{

}

Grid::Grid(int width, int height) : Grid() {
	width_ = width;
	height_ = height;
	area_ = width * height;
	dataX_ = new Cell[area_];
	dataY_ = new Cell[area_];
}

Grid::~Grid()
{
	delete[] dataX_;
	delete[] dataY_;
}

void Grid::update()
{
	const CellData currentData = getCurrentConst();
	CellData nextData = getNext();

	for (int i = 0; i < area_; i++) {
		const Cell& current = currentData[i];
		Cell& next = nextData[i];

		switch (current.getType())
		{
		case CellType::Air:
			break;
		case CellType::Block:
			next = current;
			break;
		case CellType::Sand:
			Cell* below_n = getNextDown(i);
			if (below_n) {
				(*below_n) = current;
			}
			else {
				next = current;
			}
			break;
		}
	}

	clearCurrent();
	useX_ = !useX_;
}

void Grid::draw() const {
	std::cout << "\x1B[2J\x1B[H";
	for (int i = 0; i < area_; i++) {
		if (i % width_ == 0) {
			std::cout << std::endl;
		}
		const CellData data = getCurrentConst();
		Cell& cell = data[i];
		switch (cell.getType())
		{
		case CellType::Air:
			std::cout << 'A';
			break;
		case CellType::Block:
			std::cout << 'B';
			break;
		case CellType::Sand:
			std::cout << 'S';
			break;
		}
	}
}

void Grid::setCell(CellType type, int x, int y)
{
	const int index = y * width_ + x;
	if (index < 0 || index >= area_) {
		return;
	}
	getCurrent()[index].setType(type);
}

void Grid::clearCurrent()
{
	Cell* data = nullptr;
	if (useX_) {
		data = dataX_;
	}
	else {
		data = dataY_;
	}
	for (int i = 0; i < area_; i++) {
		data[i].setType(CellType::Air);
	}
}

const Grid::CellData Grid::getCurrentConst() const {
	if (useX_) {
		return dataX_;
	}
	return dataY_;
}
Grid::CellData Grid::getCurrent()
{
	if (useX_) {
		return dataX_;
	}
	return dataY_;
}
Grid::CellData Grid::getNext() {
	if (useX_) {
		return dataY_;
	}
	return dataX_;
}

Cell* Grid::getNextDown(int index) {
	const int nextIndex = index + width_;
	if (nextIndex >= area_) {
		return nullptr;
	}
	return &getNext()[nextIndex];
}
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include "Grid.h"
#include "CellTypes.h"

void clear_screen() {
	std::cout << "\x1B[2J\x1B[H";
}
/*
typedef unsigned char byte;

constexpr int WIDTH = 10;
constexpr int HEIGHT = 10;
constexpr int AREA = WIDTH * HEIGHT;*/
constexpr int CYCLES = 11;
/*
enum CellStatus : bool {
	Dead, Alive
};

enum CellType : byte {
	Block, Sand
};

struct CellData {
	CellStatus status_;
	CellType type_;
	CellData() : status_(Dead), type_(Block) {

	}
	void paste(const CellData& data) {
		status_ = data.status_;
		type_ = data.type_;
	}
};


struct Cell {
	CellData x_, y_;
	Cell() : x_(), y_() {

	}

	CellData& getCurrent(bool which) {
		return which ? x_ : y_;
	}
	CellData& getNext(bool which) {
		return getCurrent(!which);
	}
	void persist(bool which) {
		if (which) {
			y_.paste(x_);
		}
		else {
			x_.paste(y_);
		}
	}
	void clear(bool which) {
		if (which) {
			x_.status_ = Dead;
		}
		else {
			y_.status_ = Dead;
		}
	}
};

void drawGrid(Cell grid[], bool which);*/

int main(void* args, int size) {
	Grid grid(10, 10);
	grid.setCell(CellType::Block, 0, 0);
	grid.setCell(CellType::Sand, 1, 0);
	/*Cell* grid = new Cell[AREA];
	// true => x else y
	bool x_y = true;
	{
		auto& data = grid[0].getCurrent(x_y);
		data.status_ = Alive;
		data.type_ = Sand;
		auto& data2 = grid[1].getCurrent(x_y);
		data2.status_ = Alive;
		data2.type_ = Block;
	}*/
	for (int j = 0; j < CYCLES; j++) {
		grid.draw();
		grid.update();
		/*for (int i = 0; i < AREA; i++) {
			Cell& cell = grid[i];
			CellData& data = cell.getCurrent(x_y);
			CellData& thisNext = cell.getNext(x_y);
			if (data.status_) {
				switch (data.type_)
				{
				case Block:
					cell.persist(x_y);
					break;
				case Sand:
					if (i + WIDTH >= AREA) {
						break;
					}
					Cell& below = grid[i + WIDTH];
					CellData& next = below.getNext(x_y);
					next.paste(data);
					thisNext.status_ = Dead;
					break;
				}
			}*/
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	/*drawGrid(grid, x_y);
	for (int i = 0; i < AREA && j != CYCLES - 1; i++) {
		grid[i].clear(x_y);
	}
	if (j != CYCLES - 1) {
		x_y = !x_y;
	}*/
	return 0;
}

// delete[] grid;

/*
void drawGrid(Cell grid[], bool which) {
	clear_screen();
	for (int i = 0; i < AREA; i++) {
		if (i % WIDTH == 0) {
			std::cout << std::endl;
		}
		Cell& cell = grid[i];
		CellData& data = cell.getCurrent(which);
		if (data.status_) {
			switch (data.type_)
			{
			case Block:
				std::cout << 'B';
				break;
			case Sand:
				std::cout << 'S';
				break;
			}
		}
		else {
			std::cout << 'o';
		}
	}
}*/
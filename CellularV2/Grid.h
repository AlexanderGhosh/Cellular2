#pragma once

class Cell;
enum class CellType : unsigned char;
class Grid
{
public:
	Grid();
	Grid(int width, int height);
	~Grid();
	void update();
	void draw() const;
	void setCell(CellType type, int x, int y);
private:
	typedef Cell* CellData;
	void clearCurrent();

	const CellData getCurrentConst() const;
	CellData getCurrent();
	CellData getNext();

	Cell* getNextDown(int index);

	bool useX_;
	CellData dataX_;
	CellData dataY_;
	int width_;
	int height_;
	int area_;
};


#pragma once
#include <map>

enum class CellType : unsigned char;
class CellProperties;

static class CellInfo
{
public:
	static const CellProperties& getProps(CellType type);
private:
	CellInfo();
	static std::map<CellType, CellProperties> data;
};


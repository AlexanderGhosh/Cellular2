#include "CellInfo.h"
#include "CellTypes.h"
#include "CellProperties.h"

std::map<CellType, CellProperties> CellInfo::data = {
	{ CellType::Air, {
			false,
			false
		}
	},
	{ CellType::Block, {
			true,
			true
		}
	},
	{ CellType::Sand, {
			true,
			false
		}
	}
};

CellInfo::CellInfo() {

}

const CellProperties& CellInfo::getProps(CellType type) {
	return data[type];
}
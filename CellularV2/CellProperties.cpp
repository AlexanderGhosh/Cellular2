#include "CellProperties.h"

CellProperties::CellProperties() : CellProperties(false, false)
{
}

CellProperties::CellProperties(bool solid, bool perminant) : solid_(solid), perminant_(perminant)
{
}
#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double density)
	: CBody("Parallelepiped", density)
{
}

double CParallelepiped::GetVolume()const
{
	return 0;
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	strm;
}
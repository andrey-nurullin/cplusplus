#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double density, double height)
	: CBody("Parallelepiped", density)
	, m_height(height)
{
}

double CParallelepiped::GetHeight()const
{
	return m_height;
}

double CParallelepiped::GetVolume()const
{
	return 0;
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	strm;
}
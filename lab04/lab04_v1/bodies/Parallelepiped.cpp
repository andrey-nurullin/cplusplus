#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double density, double height, double width, double length)
	: CBody("Parallelepiped", density)
	, m_height(height)
	, m_width(width)
	, m_length(length)
{
}

double CParallelepiped::GetHeight()const
{
	return m_height;
}

double CParallelepiped::GetWidth()const
{
	return m_width;
}

double CParallelepiped::GetLength()const
{
	return m_length;
}

double CParallelepiped::GetVolume()const
{
	return 0;
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	strm;
}
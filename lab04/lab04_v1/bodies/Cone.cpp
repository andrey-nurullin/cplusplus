#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double radius, double height)
	: CBody("Cone", density)
	, m_radius(radius)
	, m_height(height)
{
}

double CCone::GetVolume()const
{
	return (m_height * M_PI * pow(m_radius, 2)) / 3;
}

double CCone::GetHeight()const
{
	return m_height;
}

double CCone::GetRadius()const
{
	return m_radius;
}

void CCone::AppendProperties(std::ostream & strm) const
{
	strm;
}
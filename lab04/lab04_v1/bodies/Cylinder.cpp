#include "stdafx.h"
#include "Cylinder.h"

CCylinder::CCylinder(double density, double radius, double height)
	: CBody("Cylinder", density)
	, m_radius(radius)
	, m_height(height)
{
}

double CCylinder::GetVolume()const
{
	return (m_height * M_PI * pow(m_radius, 2));
}

double CCylinder::GetHeight()const
{
	return m_height;
}

double CCylinder::GetRadius()const
{
	return m_radius;
}

void CCylinder::AppendProperties(std::ostream & strm) const
{
	strm << "\theight = " << GetHeight() << std::endl
		<< "\tradius = " << GetRadius() << std::endl;
}
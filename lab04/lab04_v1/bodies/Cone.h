#pragma once
#include "Body.h"

class CCone final :
	public CBody
{
public:
	CCone(double density, double radius, double height);

	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;

protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_radius;
	double m_height;
};
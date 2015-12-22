#pragma once
#include "Body.h"

class CParallelepiped final :
	public CBody
{
public:
	CParallelepiped(double density, double height);

	double GetVolume() const override;
	double GetHeight() const;

protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_height;
};
#pragma once
#include "Body.h"

class CParallelepiped final :
	public CBody
{
public:
	CParallelepiped(double density, double height, double width, double lenght);

	double GetVolume() const override;
	double GetHeight() const;
	double GetWidth() const;
	double GetLength() const;

protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_height;
	double m_width;
	double m_length;
};
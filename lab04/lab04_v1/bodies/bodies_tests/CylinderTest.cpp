#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Cylinder.h"
#include <math.h>


struct Cylinder_
{
	const double expectedDensity = 9.9;
	const double expectedRadius = 10.8;
	const double expectedHeight = 12.2;
	const double expectedVolume = 4470.511479;
	const CCylinder cylinder;
	Cylinder_()
		: cylinder(expectedDensity, expectedRadius, expectedHeight)
	{}
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Cylinder, Cylinder_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&cylinder));
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).GetDensity(), expectedDensity);
}
// имеет радиус
BOOST_AUTO_TEST_CASE(has_a_radius)
{
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), expectedRadius);
}
// имеет высоту
BOOST_AUTO_TEST_CASE(has_a_height)
{
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), expectedHeight);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetVolume(), expectedVolume, 1e-7);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_a_mass)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetMass(), expectedVolume * expectedDensity, 1e-7);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Cylinder:
	density = 9.9
	volume = 4470.511479
	mass = 44258.06364
	height = 12.2
	radius = 10.8
)";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()
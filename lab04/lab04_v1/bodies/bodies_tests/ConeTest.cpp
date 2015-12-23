#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Cone.h"
#include <math.h>


struct Cone_
{
	const double expectedDensity = 13.1;
	const double expectedRadius = 12.5;
	const double expectedHeight = 7.7;
	const double expectedVolume = 5;
	const CCone cone;
	Cone_()
		: cone(expectedDensity, expectedRadius, expectedHeight)
	{}
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&cone));
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetDensity(), expectedDensity);
}
// имеет радиус
BOOST_AUTO_TEST_CASE(has_a_radius)
{
	BOOST_CHECK_EQUAL(cone.GetRadius(), expectedRadius);
}
// имеет высоту
BOOST_AUTO_TEST_CASE(has_a_height)
{
	BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
}
BOOST_AUTO_TEST_SUITE_END()
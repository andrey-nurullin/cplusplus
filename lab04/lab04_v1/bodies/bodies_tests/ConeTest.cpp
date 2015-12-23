#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Cone.h"
#include <math.h>


struct Cone_
{
	const double expectedDensity = 13.1;
	const double expectedRadius = 12.5;
	const double expectedHeight = 7.7;
	const double expectedVolume = 1259.909553;
	const CCone cone;
	Cone_()
		: cone(expectedDensity, expectedRadius, expectedHeight)
	{}
};
// �����
BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
// �������� �������� �����
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&cone));
}
// ����� ���������
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetDensity(), expectedDensity);
}
// ����� ������
BOOST_AUTO_TEST_CASE(has_a_radius)
{
	BOOST_CHECK_EQUAL(cone.GetRadius(), expectedRadius);
}
// ����� ������
BOOST_AUTO_TEST_CASE(has_a_height)
{
	BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
}
// ����� �����
BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cone).GetVolume(), expectedVolume, 1e-7);
}
BOOST_AUTO_TEST_SUITE_END()
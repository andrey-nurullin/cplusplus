#include "stdafx.h"

#include "../Parallelepiped.h"

struct Parallelepiped_
{
	const double expectedDensity = 4.3;
	const double expectedHeight = 10.5;
	const CParallelepiped parallelepiped;
	Parallelepiped_()
		: parallelepiped(expectedDensity, expectedHeight)
	{}
};

// ��������������
BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)
	// �������� �������� �����
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
	}
	// ����� ������
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), expectedHeight);
	}
BOOST_AUTO_TEST_SUITE_END()
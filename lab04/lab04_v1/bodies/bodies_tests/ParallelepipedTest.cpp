#include "stdafx.h"

#include "../Parallelepiped.h"

struct Parallelepiped_
{
	const double expectedDensity = 8.8;
	const CParallelepiped parallelepiped;
	Parallelepiped_()
		: parallelepiped(expectedDensity)
	{}
};

// Параллелепипед
BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
	}
BOOST_AUTO_TEST_SUITE_END()
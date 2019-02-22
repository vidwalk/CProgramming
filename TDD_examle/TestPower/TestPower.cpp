#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>

extern "C"{
#include <power.h>
}

TEST_GROUP(TestPower)
{
	void setup()
	{
		
	}

	void teardown()
	{
		
	}
};

TEST(TestPower, zeroTest)
{
	//Any number to the power of zero should return 1
	CHECK_EQUAL(1, power(1, 0));
	CHECK_EQUAL(1, power(0, 0));

	// Zero to the power of any positive integer > 0 = 0
	CHECK_EQUAL(0, power(0, 1));
}

TEST(TestPower, oneTests)
{
	//Any number to the power of 1 is the number itself
	CHECK_EQUAL(1, power(1, 1));
}

TEST(TestPower, manyTests)
{
	// Check the power when base > 1
	CHECK_EQUAL(2, power(2, 1));

	// Check the power when exponent > 1
	CHECK_EQUAL(4, power(2, 2));
}
#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>

extern "C"{
	// #include <xxxx.h> heaer files from production code is included here
	}

TEST_GROUP(TestSomething)
{
	void setup()
	{
		
	}

	void teardown()
	{
		
	}
};

TEST(TestSomething, myFirstTest)
{
	FAIL("The test failed!!")
}

TEST(TestSomething, SecondTest)
{
	STRCMP_EQUAL("hello", "world");
	LONGS_EQUAL(1, 2);
	CHECK(false);
}
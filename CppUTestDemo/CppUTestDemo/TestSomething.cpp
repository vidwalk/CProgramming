#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>

extern "C"{
#include <any.h> 
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

TEST(TestSomething, zeroTests)
{
	//if the string is empty it should return a -1
	CHECK_EQUAL(-1, any("car", ""));
	CHECK_EQUAL(-1, any("", "car"));
	CHECK_EQUAL(0, any("", ""));
}

TEST(TestSomething, oneTests)
{
	//if they have the same first character, then it returns 0
	CHECK_EQUAL(0, any("c", "c"));

	//if it can find the char in a string then it returns the position
	CHECK_EQUAL(2, any("car", "r"));

	//if there there isn't any character present then returns -1
	CHECK_EQUAL(-1, any("car", "b"));
}

TEST(TestSomething, manyTests)
{
	//if the second character of str2 is present in str1 then it returns the position
	CHECK_EQUAL(1, any("car", "ba"));

	//if the first str1 is made of one character it should still return 1
	CHECK_EQUAL(0, any("c", "abcdef"));

	//if there are no characters in str2 from str1
	CHECK_EQUAL(-1, any("acg", "bdef"));
}

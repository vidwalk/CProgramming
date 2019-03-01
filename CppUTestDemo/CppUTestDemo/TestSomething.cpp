#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>
#include <string.h>
extern "C"{
#include "my_strdiff.h"
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
	char a[] = "";
	char b[] = "";
	//returns -1 if the strings are identical
	CHECK_EQUAL(-1, my_strdiff(a, b));
	
}

TEST(TestSomething, oneTests)
{
	char a[] = "c";
	char b[] = " ";
	//return 0 if the first character is different
	CHECK_EQUAL(0, my_strdiff(a, b));
	char c[] = "cac";
	char d[] = "cba";
	//return the position at which the first character is different
	CHECK_EQUAL(1, my_strdiff(c, d));
}

TEST(TestSomething, manyTests)
{
	char a[] = "cac";
	char b[] = "cba";
	//return the first character that is different when more characters are different
	CHECK_EQUAL(1, my_strdiff(a, b));
}

#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>


extern "C" {

#include "my_strcpy.h"

}

TEST_GROUP(TestStrcpy)
{
	void setup()
	{

	}

	void teardown()
	{

	}
};

TEST(TestStrcpy, zeroTests)
{
	//If you don't give it a size they it will throw an error that it's corrupt around the stack
	//This means that it tries to go over the size of the array. An array of size n should run until n-1, not n.
	char a[2] = " ";
	char b[2] = " ";
	//returns -1 if the strings are identical
	my_strcpy(a, b);
	CHECK_EQUAL_C_STRING(a, b);

}

TEST(TestStrcpy, oneTests)
{
	//If you don't give it a size they it will throw an error that it's corrupt around the stack
	//This means that it tries to go over the size of the array. An array of size n should run until n-1, not n.
	char a[2] = "";
	char b[3] = "c";
	//returns -1 if the strings are identical
	my_strcpy(a, b);
	CHECK_EQUAL_C_STRING(b, a);
	char c[2] = "b";
	//return the position at which the first character is different
	my_strcpy(a, c);
	CHECK_EQUAL_C_STRING(c, a);
}

TEST(TestStrcpy, manyTests)
{
	//If you don't give it a size they it will throw an error that it's corrupt around the stack
	//This means that it tries to go over the size of the array. An array of size n should run until n-1, not n.
	char a[4] = "cac";
	char b[4] = "cba";
	//return the first character that is different when more characters are different
	my_strcpy(a, b);
	CHECK_EQUAL_C_STRING(b, a);
}

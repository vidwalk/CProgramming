#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>
#include <CppUTest/CommandLineTestRunner.h>
extern "C" {
 #include "list.h"
}

TEST_GROUP(TestList)
{
	node_t * head = NULL;
	int number1 = 1;
	void setup()
	{
		
		head = (node_t *)malloc(sizeof(node_t));
		head->item = &number1;
		head->next = NULL;
	}

	void teardown()
	{
	
	}
};

TEST(TestList, zeroTest)
{
	//Check if the next node of a list is NULL
	CHECK_EQUAL(0, head->next);
	//check if number of items is 1
	CHECK_EQUAL(1, no_of_items(head));
	//no element other than the head;
	CHECK_EQUAL(&number1, get_item(head, 0));
	//the head is removed
	CHECK_EQUAL(0, remove_item(&head, &number1));
}
TEST(TestList, oneTest)
{
	
	//Check if you can add a value to the next element in the head
	int number2 = 2;
	CHECK_EQUAL(0, add_item(head, &number2));
	//get the other node
	CHECK_EQUAL(&number2, get_item(head, 1));
	//check if number of items is 2
	CHECK_EQUAL(2, no_of_items(head));
	//The other node is removed
	CHECK_EQUAL(0, remove_item(&head, &number2));
	free(head);
}

TEST(TestList, manyTest)
{
	int number2 = 2;
	int number3 = 3;
	add_item(head, &number2);
	//Adding a third item
	CHECK_EQUAL(0, add_item(head, &number3));
	//Should be able to get the third element
	CHECK_EQUAL(&number3, get_item(head, 2))
	//The size should be 3
	CHECK_EQUAL(3, no_of_items(head));
	//The middle element should be able to be removed
	//and then the last one
	CHECK_EQUAL(0, remove_item(&head, &number2));
	CHECK_EQUAL(0, remove_item(&head, &number3));
	free(head);
	
}


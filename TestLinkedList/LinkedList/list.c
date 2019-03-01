#include "list.h"
#include "../../CppUTest/include/CppUTest/MemoryLeakDetectorMallocMacros.h"
node_t * currP;
int add_item(node_t * head,void * item)
{
	/*The current pointer points to the head*/
	currP = head;

	/*Go to the end of the list*/
	while (currP->next != NULL) {
		currP = currP->next;
	}

	/*Allocate space for the node and add the item*/
	currP->next = (node_t *) malloc(sizeof(node_t));
	currP->next->item = item;
	currP->next->next = NULL;

	/*Returns 0 if the item is added*/
	return 0;
}

void *get_item(node_t * head, unsigned short index)
{
	/*If the index of the item is 0, return directly the head*/
	if (index == 0)
	{
		return head->item;
	}

	/*The current pointer points at the start*/
	currP = head;

	/*Counter for the index so we know when to stop*/
	int i = 1;
	
	/*The List is checked for any more nodes*/
	while (currP->next != NULL) {

		/*The current pointer points to the next*/
		currP = currP->next;

		/*Returns if the counter matches the index in size*/
		if (i == index)
			return currP->item;

		/*increment the counter*/
		i++;

	}

	/*Returns the last item if the item is not found at the index*/
	return currP->item;
}

int no_of_items(node_t * head)
{
	/*The current pointer starts at the head*/
	currP = head;
	/*Initialize the current counter*/
	int i = 1;

	while (currP->next != NULL) {

		/*The current pointer receives the value of the following pointer*/
		currP = currP->next;
		/*Add one tot he size*/
		i++;

	}

	/*Return the size of the linked list*/
	return i;
}

int remove_item(node_t ** head, void * item)
{
	node_t *currP, *prevP;

	/* For 1st node, indicate there is no previous. */
	prevP = NULL;

	/*
	 * Visit each node, maintaining a pointer to
	 * the previous node we just visited.
	 */
	for (currP = *head;currP != NULL;prevP = currP, currP = currP->next) {

		if (currP->item == item) {  /* Found it. */
			if (prevP == NULL) {
				/* Fix beginning pointer. */
				*head = currP->next;
			}
			else {
				/*
				 * Fix previous node's next to
				 * skip over the removed node.
				 */
				prevP->next = currP->next;
			}

			/* Deallocate the node. */
			free(currP);

			/* Done searching. */
			return 0;
		}
		
	}
	return -1;
}
#pragma once

typedef struct node {
	void * item;
	struct node * next;
} node_t;

int add_item(node_t * head, void * item); //Return 0 if item added else -1
void *get_item(node_t * head,unsigned short index); // Return pointer to item at given index in the list
int no_of_items(node_t * head); // Return nr of items in list
int remove_item(node_t ** head,void * item); //Return 0 if item is removed else -1
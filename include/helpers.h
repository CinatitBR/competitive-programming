/* 
 * This file contains helper functions and definitions.
 *
*/

#ifndef HELPER_C
#define HELPER_C

#include <stdlib.h>

typedef struct node {
  int key;
	struct node *next;
} node;

// Represents an adjacency list.
typedef struct linked_list {
	node *head;	
	node *tail;
} linked_list;

typedef struct ad_list {
	// Array of linked lists.
	linked_list *list;
	int size;
} ad_list;

int min(int a, int b);

int max(int a, int b);

struct node *create_node(int key);

// Create and return adjacency list.
ad_list *create_ad_list(int size);

// Add node "key2" as a neighbor of "key1" 
void ad_list_push(ad_list *my_ad_list, int key1, int key2);

#endif

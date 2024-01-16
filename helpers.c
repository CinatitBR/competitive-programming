/* 
 * This file contains helper functions and definitions.
 *
*/

#ifndef HELPERS_H 
#define HELPERS_H 

#include <stdlib.h>
#include "helpers.h"

int min(int a, int b) {
  return a <= b ? a : b;
}

int max(int a, int b) {
  return a >= b ? a : b;
}

struct node *create_node(int key) {
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->key = key;
  new_node->next = NULL;

  return new_node;
}

ad_list *create_ad_list(int size) {
	ad_list *my_ad_list = (ad_list *)malloc(sizeof(ad_list));

	my_ad_list->list = (linked_list *)malloc(size * sizeof(linked_list));
	my_ad_list->size = size;
	
	return my_ad_list;
}


// Add node "key2" as a neighbor of "key1" 
void ad_list_push(ad_list *my_ad_list, int key1, int key2) {
	node *v = create_node(key2);
	linked_list *node1_list = &my_ad_list->list[key1];

	if (node1_list->head == NULL) {
		node1_list->head = v;
	}
	else {
		node1_list->tail->next = v;
	}

	node1_list->tail = v;
	
	/*
  if (ad_list[id1] == NULL) {
    ad_list[id1] = v;
  }
  else {
    ad_list[id1]->last->next = v; 
  }
  
  ad_list[id1]->last = v;
	*/
}


#endif

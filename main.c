#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node* next;
};

struct linked_list {
	struct node* head;
	struct node* tail;
};

struct node *create_node(int key) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->key = key;
	new_node->next = NULL;

	return new_node;
}

void push(struct linked_list *l, int key) {
	struct node *new_node = create_node(key);

	if (l->head == NULL) {
		l->head = new_node;
		
	}	
	else {
		l->tail->next = new_node;
	}

	l->tail = new_node;
}

void delete(struct linked_list *l, int key) {
	struct node *curr = l->head;	
	while (curr != NULL && curr->next != NULL && curr->next->key != key) {
		curr = curr->next;
	}

	if (curr != NULL && curr->next != NULL) {
		struct node* removed = curr->next;
		curr->next = removed->next;

		free(removed);
	}
}

void free_linked_list(struct linked_list *l) {
	struct node *curr = l->head;
	struct node *next = NULL;

	while (curr != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
}

int main() {
	printf("Eu quero ser um mestre..\n");
	printf("... um mestre vim!\n");
	
}


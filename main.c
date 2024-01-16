#include <stdio.h>
#include "helpers.h"


int main() {
	int n;
	scanf("%d", &n);

	ad_list *my_ad = create_ad_list(n);

	// Populate adjacency list of the tree.
	int a, b;
	for (int i = 0; i < n-1; i++) {
		scanf(" %d %d", &a, &b);
		a--;
		b--;

		ad_list_push(my_ad, a, b);
		ad_list_push(my_ad, b, a);
	}

	for (int i = 0; i < n; i++) {
		node *curr = my_ad->list[i].head;

		printf("%d: ", i);
		while (curr != NULL) {
			printf("%d ", curr->key);
			curr = curr->next;
		}
		printf("\n");
	}
}

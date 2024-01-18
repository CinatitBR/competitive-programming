#include <stdlib.h>
#include <stdio.h>

#define MAX_N 5010
#define MAX_K 100050
#define MAX_WORD 1000000

char str[MAX_N];
char *dict[MAX_K];
int k;

int main() {
	// Reads until new line, replace it with a null byte.
	gets(str);
	scanf("%d", &k);
	getchar();

	for (int i = 0; i < k; i++) {
		size_t size;
		size = getline(dict+i, &size, stdin);
		// Clear \n from the word.
		dict[i][size-1] = '\0';
	}

		
}

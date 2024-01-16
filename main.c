#include <stdlib.h>
#include <stdio.h>

#define MAX_N 200010

int n, q, a, b;
int arr[MAX_N];
long long segtree[4*MAX_N];
long long sum;

/*
  For vertex i:
  - left child: 2i+1
  - right child: 2i+2

  int i: current index
*/
void build_segtree(int i, int p, int r) {
  // if (p > r) {
  //   return;
  // }
  // Leaf.
  if (p == r) {
    segtree[i] = arr[p];
    return;
  }

  int q = (p + r) / 2;

  // Left child.
  build_segtree(2*i+1, p, q);
  // Right child.
  build_segtree(2*i+2, q+1, r);

  // Current node
  segtree[i] = segtree[2*i+1] + segtree[2*i+2];
}

/* 
  [a, b]: the query range.
  int i: the current index.
  [p, r]: the current range.
*/
void query_segtree(int a, int b, int i, int p, int r) {
	if (r < a || p > b) {
		return;
  }
  else if (p < a || r > b) {
    int q = (p + r) / 2;
    // Query left.
    query_segtree(a, b, 2*i+1, p, q);
    // Query right.
    query_segtree(a, b, 2*i+2, q+1, r);
  }
  else {
    sum += segtree[i];
    return;
  }
}

int main() {
  scanf("%d %d", &n, &q);

  for (int i = 0; i < n; i++) {
    scanf("%ld", &arr[i]);
  }

  build_segtree(0, 0, n-1);
  
  for (int  i = 0; i < q; i++) {
    // range: [a, b]
    scanf("%d %d", &a, &b);
    a--;
    b--;

    sum = 0;
    query_segtree(a, b, 0, 0, n-1);
    printf("%ld\n", sum);
  }
}

/* 
  Sum of values in range [a, b].

  TODO: build segment tree.
*/
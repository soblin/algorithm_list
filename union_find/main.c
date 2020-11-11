#include <stdio.h>
#define N 1000

int parent[N];
int representative[N];
int rank[N];

void unite(int a_, int b_) {
  int a = representative[a_];
  int b = representative[b_];

  if (rank[a] > rank[b]) {
    parent[b] = a;
    representative[b] = a;
    representative[b_] = a;
    rank[a] += 1;
  } else {
    parent[a] = b;
    representative[a] = b;
    representative[a_] = b;
    rank[b] += 1;
  }
}

int same(int a, int b) {
  return representative[a] == representative[b];
}

int main(int argc, char** argv) {
  int n, a, b, q;
  int t;

  scanf("%d %d", &n, &q);

  for (int i = 0; i < n; ++i) {
    parent[i] = i;
    representative[i] = i;
    rank[i] = 0;
  }

  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d", &t, &a, &b);
    if (t == 0)
      unite(a, b);
    else if (t == 1) {
      if (same(a, b))
        printf("1\n");
      else
        printf("0\n");
    }
  }
}

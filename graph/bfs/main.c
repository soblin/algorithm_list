#include <stdbool.h>
#include <stdio.h>

#define UNVISITED 111
#define FOUND 222
#define VISITED 333

int mat[50][50];
int color[50];
int dist[50];

int queue[100];
int head, tail;

void init() {
  for (int i = 0; i < 50; ++i) {
    dist[i] = 0;
    color[i] = UNVISITED;
    for (int j = 0; j < 50; ++j)
      mat[i][j] = 0;
  }
  // queue
  head = tail = 0;
}

int top() {
  return queue[head];
}

void pop() {
  head++;
}

void push(int val) {
  queue[tail] = val;
  tail++;
}

bool empty() {
  return head == tail;
}

int main() {
  init();

  int num_node;
  scanf("%d", &num_node);
  for (int i = 0; i < num_node; ++i) {
    int u, k, v;
    scanf("%d %d", &u, &k);
    u--;
    for (int j = 0; j < k; ++j) {
      scanf("%d", &v);
      v--;
      mat[u][v] = 1;
    }
  }

  push(0);
  while (!empty()) {
    int visit = top();
    pop();
    color[visit] = VISITED;
    for (int i = 0; i < num_node; ++i) {
      if (mat[visit][i] == 1 && color[i] == UNVISITED) {
        dist[i] = dist[visit] + 1;
        color[i] = FOUND;
        push(i);
      }
    }
  }

  for (int i = 0; i < num_node; ++i)
    printf("%d %d\n", i + 1, dist[i]);
}

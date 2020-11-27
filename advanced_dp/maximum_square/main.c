#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define N 100

static const long long INFTY = (1LL << 16);

int main() {
  int cost[N][N];

  int num_node, num_edge;
  scanf("%d %d", &num_node, &num_edge);

  for (int i = 0; i < num_node; ++i) {
    for (int j = 0; j < num_node; ++j) {
      cost[i][j] = (i == j) ? 0 : INFTY;
    }
  }
  for (int i = 0; i < num_edge; ++i) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    cost[u][v] = c;
  }

  for (int k = 0; k < num_node; ++k) {
    for (int i = 0; i < num_node; ++i) {
      if (cost[i][k] == INFTY)
        continue;
      for (int j = 0; j < num_node; ++j) {
        if (cost[k][j] == INFTY)
          continue;
        int cost_ = cost[i][k] + cost[k][j];
        if (cost_ < cost[i][j])
          cost[i][j] = cost_;
      }
    }
  }

  bool negative = false;
  for (int i = 0; i < num_node; ++i) {
    if (cost[i][i] < 0) {
      negative = true;
      break;
    }
  }

  if (negative) {
    printf("NEGATIVE CYCLE\n");
  } else {
    for (int i = 0; i < num_node; ++i) {
      for (int j = 0; j < num_node; ++j) {
        if (j != 0)
          printf(" ");
        if (cost[i][j] == INFTY)
          printf("INF");
        else
          printf("%d", cost[i][j]);
      }
      printf("\n");
    }
  }
}

#include <cstdio>
#include <iostream>
#include <vector>
#define N 100
#define INFTY 100000

using namespace std;

int main() {
  int num_node, num_edge;

  cin >> num_node >> num_edge;

  vector<int> graph[N];
  for (int i = 0; i < num_node; ++i) {
    graph[i].resize(num_node);
    for (int j = 0; j < num_node; ++j) {
      graph[i][j] = (i == j) ? 0 : INFTY;
    }
  }

  for (int i = 0; i < num_edge; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u][v] = c;
  }

  // warshall floyd
  for (int k = 0; k < num_node; ++k) {
    for (int i = 0; i < num_node; ++i) {
      if (graph[i][k] == INFTY)
        continue;
      for (int j = 0; j < num_node; ++j) {
        if (graph[k][j] == INFTY)
          continue;
        int cost = graph[i][k] + graph[k][j];
        if (cost < graph[i][j])
          graph[i][j] = cost;
      }
    }
  }

  bool negative = false;
  for (int i = 0; i < num_node; ++i) {
    if (graph[i][i] < 0) {
      negative = true;
      break;
    }
  }

  if (negative) {
    printf("NEGATIVE CYCLE");
    return 0;
  }
  for (int i = 0; i < num_node; ++i) {
    for (int j = 0; j < num_node; ++j) {
      if (j != 0)
        printf(" ");
      if (graph[i][j] == INFTY)
        printf("INF");
      else
        printf("%d", graph[i][j]);
    }
    printf("\n");
  }
}

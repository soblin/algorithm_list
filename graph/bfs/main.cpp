#include <iostream>
#include <queue>
#define N 1000
#define UNVISITED 111
#define FOUND 222
#define FINISHED 333

using namespace std;

int main() {
  int color[N];
  int mat[N][N];
  int dist[N];
  int num_node;
  cin >> num_node;

  // init
  for (int i = 0; i < num_node; ++i) {
    color[i] = UNVISITED;
    dist[i] = 0;
    for (int j = 0; j < num_node; ++j)
      mat[i][j] = 0;
  }

  for (int i = 0; i < num_node; ++i) {
    int u, v, k;
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; ++j) {
      cin >> v;
      v--;
      mat[u][v] = 1;
    }
  }

  queue<int> q;
  q.push(0);
  while (not q.empty()) {
    int visit = q.front();
    q.pop();
    color[visit] = FINISHED;
    for (int i = 0; i < num_node; ++i) {
      if (mat[visit][i] == 1 and color[i] == UNVISITED) {
        q.push(i);
        color[i] = FOUND;
        dist[i] = dist[visit] + 1;
      }
    }
  }

  for (int i = 0; i < num_node; ++i) {
    std::cout << i + 1 << ' ' << dist[i] << '\n';
  }
}

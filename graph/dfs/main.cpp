#include <iostream>
#include <stack>
#include <vector>
#define N 100

using namespace std;

int n, M[N][N];
int color[N], found_time[N], finished_time[N], t;
int next_visit_cache[N];

enum Status { UNVISITED = 0, FOUND, FINISHED };

int next_visit(int u) {
  // yield the adjacent nodes of u, from low index to high index
  for (int i = next_visit_cache[u]; i < n; ++i) {
    next_visit_cache[u]++;
    if (M[u][i] == 1)
      return i;
  }
  return -1;
}

void dfs_visit(int r) {
  for (int i = 0; i < n; ++i)
    next_visit_cache[i] = 0;

  color[r] = FOUND;
  t++;
  found_time[r] = t;

  stack<int> s;
  s.push(r);
  while (not s.empty()) {
    int cur = s.top();
    int next = next_visit(cur);
    if (next == -1) {
      // this node is consumed.
      color[cur] = FINISHED;
      t++;
      finished_time[cur] = t;
      s.pop();
    } else {
      if (color[next] == UNVISITED) {
        // found the next
        color[next] = FOUND;
        t++;
        found_time[next] = t;
        s.push(next);
      }
      // else: `next` is already visitted, skip(t does not incremented!)
    }
  }
}

int main() {
  int u, k, v;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      M[i][j] = 0;
  }

  for (int i = 0; i < n; ++i) {
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; ++j) {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }

  // dfs()
  for (int i = 0; i < n; ++i) {
    color[i] = UNVISITED;
    next_visit_cache[i] = 0;
  }

  t = 0;

  for (int i = 0; i < n; ++i) {
    if (color[i] == UNVISITED)
      dfs_visit(i);
  }

  for (int i = 0; i < n; ++i) {
    cout << i + 1 << ' ' << found_time[i] << ' ' << finished_time[i] << endl;
  }
}

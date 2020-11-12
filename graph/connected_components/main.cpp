#include <iostream>
#include <stack>
#include <vector>
#define N 1000

using namespace std;

vector<int> G[N];
int color[N];
int color_id;
int n;

void assign_color_rec(int u) {
  color[u] = color_id;
  for (const auto& v : G[u]) {
    if (color[v] == -1)
      assign_color_rec(v);
  }
}

void assign_color_stack(int u) {
  stack<int> s;
  s.push(u);
  while (not s.empty()) {
    int visit = s.top();
    color[visit] = color_id;
    s.pop();
    for (const auto& v : G[visit]) {
      if (color[v] == -1)
        s.push(v);
    }
  }
}

int main() {
  color_id = 0;
  int s, t, m, q;
  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    color[i] = -1;

  for (int i = 0; i < m; ++i) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  for (int i = 0; i < n; ++i) {
    if (color[i] == -1)
      assign_color_stack(i);
    color_id++;
  }

  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> s >> t;
    if (color[s] == color[t])
      cout << "yes\n";
    else
      cout << "no\n";
  }
}

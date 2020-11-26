#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
#define N 100
#define INFTY 100000

using namespace std;

int main() {
  int n, m;

  cin >> n >> m;
  vector<int> vals;
  vector<int> costs;
  vals.resize(m);
  costs.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int v;
    cin >> v;
    vals[i] = v;
  }

  for (int i = 0; i < costs.size(); ++i)
    costs[i] = INFTY;

  costs[0] = 0;
  for (int i = 0; i < vals.size(); ++i) {
    for (int j = 0; j + vals[i] <= n; ++j) {
      costs[j + vals[i]] = min(costs[j + vals[i]], costs[j] + 1);
    }
  }

  cout << costs[n] << endl;
}

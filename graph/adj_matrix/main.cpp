#include <iostream>
#define N 100

using namespace std;

int mat[N][N];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      mat[i][j] = 0;
    }
  }

  int v, k, u;
  for (int i = 0; i < n; ++i) {
    cin >> v >> k;
    v--;
    for (int j = 0; j < k; ++j) {
      cin >> u;
      u--;
      mat[v][u] = 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ' ' << mat[i][j];
    }
    cout << '\n';
  }
}

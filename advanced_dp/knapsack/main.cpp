#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define NUM 100
#define INFTY 100000

#define UNDECIDED 111
#define VERTICAL 222
#define DIAGONAL 333

using namespace std;

int main() {
  int N, W;
  int costs[NUM][NUM];
  int transition[NUM][NUM];
  cin >> N >> W;
  vector<int> v;
  vector<int> w;
  v.push_back(0);
  w.push_back(0);
  for (auto i = 0; i < N; ++i) {
    int v_, w_;
    cin >> v_ >> w_;
    v.push_back(v_);
    w.push_back(w_);
  }
  for (int i = 0; i <= N; ++i) {
    costs[i][0] = 0;
    for (int j = 0; j <= W; ++j) {
      transition[i][j] = UNDECIDED;
    }
  }
  for (int i = 0; i <= W; ++i)
    costs[0][i] = 0;

  vector<int> selection;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= W; ++j) {
      if (w[i] > j)
        costs[i][j] = 0;
      else {
        int w1 = costs[i - 1][j];
        int w2 = costs[i - 1][j - w[i]] + v[i];
        if (w1 > w2) {
          costs[i][j] = w1;
          transition[i][j] = VERTICAL;
        } else {
          costs[i][j] = w2;
          transition[i][j] = DIAGONAL;
        }
      }
    }
  }

  int x = N;
  int y = W;
  for (;;) {
    if (transition[x][y] == VERTICAL) {
      // x is not used
      x--;
    } else {
      selection.push_back(x);
      y -= w[x--];
    }
    if (transition[x][y] == UNDECIDED)
      break;
  }

  reverse(selection.begin(), selection.end());
  for (auto&& item : selection)
    cout << item << ' ';

  cout << costs[N][W] << endl;
}

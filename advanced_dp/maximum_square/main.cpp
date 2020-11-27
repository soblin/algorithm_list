#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h_, w_;
  cin >> h_ >> w_;
  const int H = h_;
  const int W = w_;
  vector<vector<int>> board;
  vector<vector<int>> costs;
  for (int i = 0; i < H; ++i) {
    board.push_back(vector<int>());
    costs.push_back(vector<int>());
    for (int j = 0; j < W; ++j) {
      int c;
      cin >> c;
      board[i].push_back(c);
      costs[i].push_back(-1);
    }
  }

  for (int i = 0; i < H; ++i)
    costs[i][0] = (board[i][0] == 0) ? 1 : 0;

  for (int j = 0; j < W; ++j)
    costs[0][j] = (board[0][j] == 0) ? 1 : 0;

  int opt = 0;
  for (int i = 1; i < H; ++i) {
    for (int j = 1; j < W; ++j) {
      if (board[i][j] == 1)
        costs[i][j] = 0;
      else {
        int above_left = costs[i - 1][j - 1];
        int above = costs[i - 1][j];
        int left = costs[i][j - 1];
        costs[i][j] = min(above_left, min(above, left)) + 1;
        if (costs[i][j] > opt)
          opt = costs[i][j];
      }
    }
  }

  cout << opt * opt << endl;
}

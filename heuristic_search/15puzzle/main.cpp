#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define N 4
#define N2 16
#define LIMIT 100

using namespace std;

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u', 'l', 'd', 'r'};
int MDT[N2][N2];

struct Puzzle {
  int board[15];
  int space;
  int MD;
};

Puzzle state;
int limit;
int path[LIMIT];

int getAllMD(const Puzzle& p) {
  int sum = 0;
  for (int i = 0; i < N2; ++i) {
    if (p.board[i] == N2)
      continue;
    // value `board[i]` must be placed at board@[board[i]-1]
    //
    sum += MDT[i][p.board[i] - 1];
  }
  return sum;
}

bool isSolved() {
  for (int i = 0; i < N2; ++i) {
    if (state.board[i] != (i + 1)) {
      return false;
    }
  }
  return true;
}

bool dfs(int depth, int prev) {
  // prev denotes previous motion: 0-3
  if (state.MD == 0)
    return true;
  // state.MD denotes the manhattan distance between current state of interest
  // of target
  if (depth + state.MD > limit)
    return false;

  int sx = state.space / N;
  int sy = state.space % N;
  Puzzle tmp;

  for (int r = 0; r < 4; ++r) {
    if (max(prev, r) - min(prev, r) == 2) {
      // diagonal motion is ignored
      continue;
    }
    int tx = sx + dx[r];
    int ty = sy + dy[r];
    // out of range
    if (tx < 0 or ty < 0 or tx >= N or ty >= N)
      continue;
    // copy current state
    tmp = state;
    // calculate the change of MD only for the swapped elements
    state.MD -= MDT[tx * N + ty][state.board[tx * N + ty] -
                                 1]; // [tx][ty] becomes `space`, so subtracted
    state.MD += MDT[sx * N + sy][state.board[tx * N + ty] -
                                 1]; // [sx][sy] becomes board[tx][ty], so added
    state.space = tx * N + ty;
    if (dfs(depth + 1, r)) {
      path[depth] = r;
      return true;
    }
    // return to previous state
    state = tmp;
  }

  return false;
}

string iterative_depthening_search(Puzzle in) {
  in.MD = getAllMD(in);

  for (limit = in.MD; limit <= LIMIT; limit++) {
    state = in;
    if (dfs(0, -100)) {
      string ans = "";
      for (int i = 0; i < limit; ++i)
        ans += dir[path[i]];
      return ans;
    }
  }

  return "unsolvable";
}
int main() {
  for (int i = 0; i < N2; ++i) {
    for (int j = 0; j < N2; ++j) {
      MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
    }
  }

  Puzzle in;

  for (int i = 0; i < N2; ++i) {
    cin >> in.board[i];
    if (in.board[i] == 0) {
      in.board[i] = N2;
      in.space = i;
    }
  }

  string ans = iterative_depthening_search(in);
  cout << ans << endl;
  return 0;
}

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Puzzle {
  int board[9];
  int space;
  string path;

  bool operator<(const Puzzle& p) const {
    for (int i = 0; i < 9; ++i) {
      if (board[i] == p.board[i])
        continue;
      return board[i] > p.board[i];
    }
    return false;
  }
};

bool isTarget(const Puzzle& p) {
  for (int i = 0; i < 9; ++i)
    if (p.board[i] != (i + 1))
      return false;
  return true;
}

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u', 'l', 'd', 'r'};

string bfs(Puzzle s) {
  queue<Puzzle> Q;
  map<Puzzle, bool> V; // VはBFSで探索済みを格納
  Puzzle u, v;
  s.path = "";
  Q.push(s);
  V[s] = true;

  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (isTarget(u))
      return u.path;
    int sx = u.space / 3;
    int sy = u.space % 3;
    for (int r = 0; r < 4; ++r) {
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if (tx < 0 or ty < 0 or tx >= 3 or ty >= 3)
        continue;
      v = u;
      swap(v.board[u.space], v.board[tx * 3 + ty]);
      v.space = tx * 3 + ty;
      if (V[v] == false) {
        V[v] = true;
        v.path += dir[r];
        Q.push(v);
      }
    }
  }

  return "unsolvable";
}

int main() {
  Puzzle in;
  for (int i = 0; i < 9; ++i) {
    cin >> in.board[i];
    if (in.board[i] == 0) {
      in.board[i] = 9;
      in.space = i;
    }
  }

  cout << bfs(in) << endl;
  return 0;
}

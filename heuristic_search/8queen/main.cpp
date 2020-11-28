#include <iostream>
#include <vector>
#define N (8)
#define FREE -1
#define NOT_FREE 1

using namespace std;

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];
bool finished = false;

void init() {
  for (int i = 0; i < N; ++i)
    row[i] = col[i] = FREE;
  for (int i = 0; i < 2 * N - 1; ++i)
    dpos[i] = dneg[i] = FREE;
}

void print() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (j == row[i])
        cout << 'Q';
      else
        cout << '.';
    }
    cout << '\n';
  }
}

void rec(int i) {
  if (finished)
    return;

  if (i == N) {
    finished = true;
    print();
    return;
  }
  // check recursion for board[i]
  if (row[i] != FREE) {
    // goto next row
    rec(i + 1);
    return;
  }
  for (int j = 0; j < N; ++j) {
    if (col[j] == NOT_FREE or dpos[i + j] == NOT_FREE or
        dneg[i + (N - 1 - j)] == NOT_FREE)
      continue;
    // place a queen on (i, j)
    row[i] = j;
    col[j] = dpos[i + j] = dneg[i + (N - 1 - j)] = NOT_FREE;
    rec(i + 1);
    // if not found, mark (i, j) as free
    row[i] = col[j] = dpos[i + j] = dneg[i + (N - 1 - j)] = FREE;
  }
}

int main() {
  init();

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int r, c;
    cin >> r >> c;
    row[r] = c;
    col[c] = dpos[r + c] = dneg[r + (N - 1 - c)] = NOT_FREE;
  }

  // start with 0th row
  rec(0);
}

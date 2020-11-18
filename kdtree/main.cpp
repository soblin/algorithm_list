#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Node {
public:
  int index; // indexはTにおける添字()
  int p, l, r;
  Node() {}
};

class Point {
public:
  int id, x, y; // idは入力された順番でTとPのインデックスには関係ない
  Point() : id(0), x(0), y(0) {}
  Point(int id, int x, int y) : id(id), x(x), y(y) {}
  const Point& operator=(const Point& rhs) {
    id = rhs.id;
    x = rhs.x;
    y = rhs.y;
  }
  bool operator<(const Point& rhs) {
    return id < rhs.id; // 使わないけど一応定義しているだけ
  }
};

static const int MAX = 1000000;
static const int NIL = -1;

int N;
Point P[MAX];
Node T[MAX];

int np;

bool lessX(const Point& p1, const Point& p2) {
  return p1.x < p2.x;
}
bool lessY(const Point& p1, const Point& p2) {
  return p1.y < p2.y;
}

// l, rはTにおける添字
int makeKDTree(int l, int r, int depth) {
  if (r <= l)
    return NIL;
  int mid = (l + r) / 2;
  int t = np++;
  if (depth % 2 == 0) {
    // xで
    sort(P + l, P + r, lessX);
  } else {
    sort(P + l, P + r, lessY);
  }
  T[t].index = mid;
  T[t].l = makeKDTree(l, mid, depth + 1);
  T[t].r = makeKDTree(mid + 1, r, depth + 1);

  return t;
}
// 戻り値はpreorderでの訪問番号

void find(
    int v, int sx, int tx, int sy, int ty, int depth, vector<Point>& ans) {
  int x = P[T[v].index].x;
  int y = P[T[v].index].y;

  if (sx <= x and x <= tx and sy <= y and y <= ty)
    ans.push_back(P[T[v].index]);

  if (depth % 2 == 0) {
    if (T[v].l != NIL and sx <= x)
      find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
    if (T[v].r != NIL and x <= tx)
      find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
  } else {
    if (T[v].l != NIL and sy <= y)
      find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
    if (T[v].r != NIL and y <= ty)
      find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
  }
}

int main() {
  int x, y;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &x, &y);
    P[i] = Point(i, x, y);
    T[i].l = T[i].r = T[i].p = NIL;
  }

  np = 0;

  int root = makeKDTree(0, N, 0);
  int q;
  scanf("%d", &q);
  int sx, tx, sy, ty;
  vector<Point> ans;
  stringstream ans_str;
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    ans.clear();
    find(root, sx, tx, sy, ty, 0, ans);
    sort(ans.begin(), ans.end());
    for (int j = 0; j < ans.size(); ++j) {
      ans_str << ans[j].id << ' ';
    }
    ans_str << '\n';
  }

  cout << ans_str.str();
  return 0;
}

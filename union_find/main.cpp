#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct NodeT {
  T val;
  NodeT<T>* parent;
  T root;
  T rank;
};

typedef NodeT<int> Node;

class DisjointSet {
public:
  vector<int> rank, p;

  DisjointSet() {}
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    for (int i = 0; i < size; ++i)
      makeSet(i);
  }

  void makeSet(int i) {
    p[i] = i;
    rank[i] = 0;
  }

  void unite(int x, int y) {
    if (same(x, y))
      return;

    x = findSet(x);
    y = findSet(y);
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else if (rank[x] == rank[y]) {
      p[x] = y;
      rank[x] += 1;
    } else {
      p[x] = y;
    }
  }

  bool same(int x, int y) {
    return findSet(x) == findSet(y);
  }

  int findSet(int x) {
    if (x != p[x]) {
      p[x] = findSet(p[x]);
    }

    return p[x];
  }
};
int main() {
  int n, a, b, q;

  int t;

  cin >> n >> q;

  DisjointSet ds = DisjointSet(n);

  for (int i = 0; i < q; ++i) {
    cin >> t >> a >> b;
    if (t == 0)
      ds.unite(a, b);
    else if (t == 1) {
      if (ds.same(a, b))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }
}

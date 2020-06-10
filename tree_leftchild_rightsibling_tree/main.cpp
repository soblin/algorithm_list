#include <iostream>
using namespace std;
#define MAX 100000
#define NIL -1

struct Node {int parent, left, right;};

Node Tree[MAX];
int n, Depth[MAX];

void print(int u){
  cout << "node " << u << ": ";
  cout << "parent = " << Tree[u].parent << ", ";
  cout << "depth = " << Depth[u] << ", ";

  if(Tree[u].parent == NIL) cout << "root, ";
  else if (Tree[u].left == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";

  for(int i = 0, c = Tree[u].left; c != NIL; ++i, c = Tree[c].right){
    if(i) cout << ", ";
    cout << c;
  }
  cout << "]\n";
}

int rec(int u, int p){
  Depth[u] = p;
  if(Tree[u].right != NIL) rec(Tree[u].right, p);
  if(Tree[u].left != NIL) rec(Tree[u].left, p+1);
}

int main(){
  int d, v, c, l, r;
  cin >> n;
  for(int i = 0; i < n; ++i)
    Tree[i].parent = Tree[i].left = Tree[i].right = NIL;

  for(int i = 0; i < n; ++i){
    cin >> v >> d;
    for(int j = 0; j < d; ++j){
      cin >> c;
      if(j == 0) Tree[v].left = c;
      else Tree[l].right = c;
      l = c;
      Tree[c].parent = v;
    }
  }

  for(int i = 0; i < n; ++i){
    if(Tree[i].parent == NIL)
      r = i;
  }

  rec(r, 0);

  for(int i = 0; i < n; ++i) print(i);

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#define INFTY 1000000
#define UNVISITED 111
#define FOUND 222
#define VISITED 333

using namespace std;

class UnionFind {
 public:
  UnionFind(int sz){
    parent_.resize(sz);
    height_.resize(sz);
    for(unsigned i = 0; i < parent_.size(); ++i){
      makeNode(i);
    }
  }
  int findSet(int p){
    if (parent_[p] == p) return p;
    else{
      return parent_[p] = findSet(parent_[p]);
    }
  }
  bool same(int u, int v){
    return findSet(u) == findSet(v);
  }
  void unite(int u_, int v_){
    int u = findSet(u_);
    int v = findSet(v_);
    
    if(height_[u] > height_[v]){
      parent_[v] = u;
    }
    else if (height_[u] < height_[v]){
      parent_[u] = v;
    }
    else{
      parent_[v] = u;
      height_[u]++;
    }
  }
 private:
  vector<int> parent_;
  vector<int> height_;
  void makeNode(int p){
    parent_[p] = p;
    height_[p] = 0;
  }
};

template <typename T>
class Edge {
 public:
  Edge() : Edge(0, 0, 0){}
  Edge(T src, T dst, T cost) : src_(src), dst_(dst), cost_(cost){}
  Edge(const Edge<T>& lhs){
    this->src_ = lhs.src();
    this->dst_ = lhs.dst();
    this->cost_ = lhs.cost();
  }
  inline T src() const { return src_; }
  inline T dst() const{ return dst_; }
  inline T cost() const {return cost_; }
 private:
  T src_;
  T dst_;
  T cost_;
};

template <typename T>
bool lessCost(const Edge<T> &lhs, const Edge<T> &rhs){
  return lhs.cost() < rhs.cost();
}

int main(){
  int num_node, num_edge;
  cin >> num_node >> num_edge;

  vector<Edge<int>> edges;

  for(int i = 0; i < num_edge; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    edges.emplace_back(u, v, c);
  }

  // ascending order
  sort(edges.begin(), edges.end(), lessCost<int>);
  UnionFind union_find(num_edge+1);
  
  int opt_cost = 0;
  // first edge
  for(int i = 0; i < edges.size(); ++i){
    int src = edges[i].src();
    int dst = edges[i].dst();
    int cost = edges[i].cost();
    if(not union_find.same(src, dst)){
      union_find.unite(src, dst);
      opt_cost += cost;
    }
  }
  cout << opt_cost << endl;
}

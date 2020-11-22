#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

#define UNVISITED 111
#define DONE 333

#define N 100

using namespace std;

vector<int> graph[N];
list<int> done;
int color[N];

void dfs(int u){
  color[u] = DONE;
  
  for(auto&& v : graph[u]){
    if (color[v] == UNVISITED) dfs(v);
  }

  done.push_front(u);
}

int main(){
  int num_node, num_edge;

  cin >> num_node >> num_edge;

  for(int i = 0; i < num_node; ++i){
    color[i] = UNVISITED;
  }
  
  for(int i = 0; i < num_edge; ++i){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }

  for(int u = 0; u < num_node; ++u){
    if (color[u] == UNVISITED) dfs(u);
  }

  for(auto&& u : done)
    cout << u << endl;
}

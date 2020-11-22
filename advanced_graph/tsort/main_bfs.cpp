#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
#define N 100
#define UNVISITED 111
#define QUEUED 222
#define DONE 333

using namespace std;

vector<bool> graph[N];
list<int> done;

int color[N];
int indeg[N];

void bfs(int u_, const int num_node){
  queue<int> queued_nodes;
  queued_nodes.push(u_);
  color[u_] = QUEUED;
  while(!queued_nodes.empty()){
    int u = queued_nodes.front(); queued_nodes.pop();
    color[u] = DONE;
    done.push_back(u);
    for(int v = 0; v < num_node; ++v){
      if (graph[u][v]){
        indeg[v]--;
        if (indeg[v] == 0 and color[v] == UNVISITED){
          color[v] = QUEUED;
          queued_nodes.push(v);
        }
      }
    }
  }
}
int main(){
  int num_node, num_edge;

  cin >> num_node >> num_edge;
  
  for(int i = 0; i < num_node; ++i){
    graph[i].resize(num_node);
    color[i] = UNVISITED;
    indeg[i] = 0;
    for(int j = 0; j < num_node; ++j){
      graph[i][j] = false;
    }
  }

  for(int i = 0; i < num_edge; ++i){
    int u, v;
    cin >> u >> v;
    graph[u][v] = true;
    indeg[v]++;
  }

  for(int u = 0; u < num_node; ++u){
    if (indeg[u] == 0 and color[u] == UNVISITED)
      bfs(u, num_node);
  }

  for(auto&& iter: done)
    cout << iter << endl;
}

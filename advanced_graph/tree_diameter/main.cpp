#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#define N 100
#define INFTY 1000000

using namespace std;

vector<pair<int/*vertex*/, int/*cost*/>> graph[N];
double dist[N];

void calc_dist(const int start, const int num_node){
  for(int i = 0; i < num_node; ++i)
    dist[i] = INFTY;
  queue<int> nodes_queue;
  nodes_queue.push(start);
  dist[start] = 0;
  while(!nodes_queue.empty()){
    int u = nodes_queue.front(); nodes_queue.pop();
    for(int i = 0;  i < graph[u].size(); ++i){
      int v = graph[u][i].first;
      int c = graph[u][i].second;
      if (dist[v] == INFTY){
        dist[v] = dist[u] + c;
        nodes_queue.push(v);
      }
    }
  }
}

int main(){
  int num_node;
  cin >> num_node;

  for(int i = 0; i < num_node-1; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].emplace_back(v, c);
    graph[v].emplace_back(u, c);
  }

  calc_dist(0, num_node);
  int max_dist1 = 0;
  int max_dist_node1 = 0;
  for(int i = 0; i < num_node; ++i){
    if(dist[i] > max_dist1 and dist[i] != INFTY){
      max_dist1 = dist[i];
      max_dist_node1= i;
    }
  }

  calc_dist(max_dist_node1, num_node);
  int max_dist2 = 0;
  int max_dist_node2 = 0;
  for(int i = 0; i < num_node; ++i){
    if(dist[i] > max_dist2 and dist[i] != INFTY){
      max_dist2 = dist[i];
      max_dist_node2 = i;
    }
  }

  cout << max_dist2 << endl;
}

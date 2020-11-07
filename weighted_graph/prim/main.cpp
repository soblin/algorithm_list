#include <iostream>
#include <vector>
#define INFTY 1000000
#define UNVISITED 111
#define FOUND 222
#define VISITED 333

using namespace std;

int main(){
  int num_node;
  cin >> num_node;
  
  vector< vector<int> > graph;
  vector<int> color;
  vector<int> parent;
  vector<int> cost;
  
  for(int i = 0; i < num_node; ++i){
    graph.push_back(vector<int>());
    color.push_back(UNVISITED);
    parent.push_back(-1);
    cost.push_back(INFTY);
    
    for(int j = 0; j < num_node; ++j){
      int w;
      cin >> w;
      if (w == -1)
        w = INFTY;      
      graph[i].push_back(w);
    }
  }

  int start = 0;
  cost[start] = 0;
  color[start] = FOUND;
  parent[start] = -1;
  
  while(1){
    int min_cost_found_node = -1;
    int min_cost = INFTY;
    // find min-cost node from FOUND nodes
    for(int i = 0; i < num_node; ++i){
      if(color[i] == FOUND and cost[i] < min_cost){
        min_cost_found_node = i;
        min_cost = cost[i];
      }
    }

    if (min_cost_found_node == -1){
      // there are no nodes to be searched
      break;
    }

    color[min_cost_found_node] = VISITED;
    for(int i = 0; i < num_node; ++i){
      if(color[i] != VISITED and
         graph[min_cost_found_node][i] != INFTY){
        if(cost[i] > graph[min_cost_found_node][i]){
          color[i] = FOUND;
          cost[i] = graph[min_cost_found_node][i];
          parent[i] = min_cost_found_node;
        }
      }
    }
  }

  int sum = 0;
  for(int i = 0; i < num_node; ++i){
    if(parent[i] != -1)
      sum += graph[i][parent[i]];
  }

  cout << sum;
}

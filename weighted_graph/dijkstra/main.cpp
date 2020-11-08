#include <iostream>
#include <vector>
#define INFTY 1000000
#define UNVISITED 111
#define FOUND 222
#define VISITED 333
#define N 100

using namespace std;

int mat[N][N];
int color[N];
int cost[N];
int parent[N];

int main(){
  int num_node;
  cin >> num_node;

  for(int i = 0; i < num_node; ++i){
    for(int j = 0; j < num_node; ++j){
      mat[i][j] = INFTY;
    }
    color[i] = UNVISITED;
    cost[i] = INFTY;
  }

  int u, k, c, v;
  for(int i = 0; i < num_node; ++i){
    cin >> u >> k;
    for(int j = 0; j < k; ++j){
      cin >> v >> c;
      mat[u][v] = c;
    }
  }

  int start = 0;
  cost[start] = 0;
  color[start] = FOUND;
  parent[start] = -1;
  while(1){
    int min_cost_found_node = -1;
    int min_cost = INFTY;
    for(int i = 0; i < num_node; ++i){
      if(cost[i] < min_cost and color[i] == FOUND){
        min_cost_found_node = i;
        min_cost = cost[i];
      }
    }
    if(min_cost_found_node == -1)
      break;

    color[min_cost_found_node] = VISITED;
    for(int i = 0; i < num_node; ++i){
      if(color[i] != VISITED and
         mat[min_cost_found_node][i] != INFTY){
        int new_cost = cost[min_cost_found_node] + mat[min_cost_found_node][i];
        if(cost[i] > new_cost){
          cost[i] = new_cost;
          color[i] = FOUND;
          parent[i] = min_cost_found_node;
        }
      }
    }
  }
  for(int i = 0; i < num_node; ++i)
    cout << i << ' ' << (cost[i] == INFTY ? -1 : cost[i]) << endl;
}

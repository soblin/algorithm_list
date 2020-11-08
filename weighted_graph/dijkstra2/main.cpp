#include <iostream>
#include <vector>
#include <queue>
#define INFTY 1000000
#define UNVISITED 111
#define FOUND 222
#define VISITED 333

using namespace std;

int main(){
  int num_node;
  int k, u, v, c;

  cin >> num_node;
  vector<pair<int, int>> mat[num_node];
  vector<int> color, cost, parent;
  for(int i = 0; i < num_node; ++i){
    cin >> u >> k;
    for(int j = 0; j < k; ++j){
      cin >> v >> c;
      mat[u].emplace_back(make_pair(v, c));
    }
    color.push_back(UNVISITED);
    cost.push_back(INFTY);
    parent.push_back(-1);
  }

  priority_queue<pair<int /*cost*/, int/*id*/>> PQ;
  int start = 0;
  cost[start] = 0;
  color[start] = FOUND;
  PQ.push(make_pair(0, start));

  while(!PQ.empty()){
    auto f = PQ.top(); PQ.pop();
    int min_cost_open_node = f.second;
    color[min_cost_open_node] = VISITED;

    // 下のwhileでpushしたvはPQから削除される必要があるが，直接vをPQから削除できない
    // ここでcontinueされない場合，下のwhileで昔pushされた最短でないものを削除している
    if(cost[min_cost_open_node] < f.first * (-1)) continue;

    for(int j = 0; j < mat[min_cost_open_node].size(); ++j){
      int v = mat[min_cost_open_node][j].first;
      if(color[v] == VISITED) continue;
      int new_cost = cost[min_cost_open_node] + mat[min_cost_open_node][j].second;
      if(cost[v] > new_cost){
        cost[v] = new_cost;
        // priority_queue prioritize larger value
        PQ.push(make_pair(-cost[v], v));
        color[v] = FOUND;
        parent[v] = min_cost_open_node;
      }
    }
  }
  for(int i = 0; i < num_node; ++i)
    cout << i << ' ' << (cost[i] == INFTY ? -1 : cost[i]) << endl;
}

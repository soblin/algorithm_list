#include <iostream>
#define N 1000
#define INFTY 10000000

using namespace std;

int mat_chain_product(int cost[][N], const int from, const int to, const int *p){
  if(from == to){
    cost[from][to] = 0;
    return 0;
  }
  else if(cost[from][to] != -1)
    return cost[from][to];

  else{
    int min = INFTY;
    for(int k = from; k < to; ++k){
      int tmp = mat_chain_product(cost, from, k, p) + mat_chain_product(cost, k+1, to, p) + p[from] * p[k+1] * p[to+1];
      if (tmp < min) min = tmp;
    }
    cost[from][to] = min;
    return min;
  }
}

int main(){
  int n;
  cin >> n;

  int p[N];
  int cost[N][N];
  
  for(int i = 0; i < n; ++i){
    int a, b;
    cin >> a >> b;
    p[i] = a;
    p[i+1] = b;
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cost[i][j] = -1;
    }
  }

  cout << mat_chain_product(cost, 0, n-1, p) << endl;
}

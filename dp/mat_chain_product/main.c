#include <stdio.h>
#include <string.h>

#define INFTY 1000000
const int N = 1000;

int mat_chain_product(int cost[][N], int from, int to, const int *p){
  if (from == to){
    cost[from][to] = 0;
    return 0;
  }
  else if (cost[from][to] != -1)
    return cost[from][to];
  
  else{
    int min = INFTY;
    for(int k = from; k < to; ++k){
      // maxtix M_k is of size p[k] x p[k+1]
      int tmp = mat_chain_product(cost, from, k, p) + mat_chain_product(cost, k+1, to, p) + p[from] * p[k+1] * p[to+1];
      if (tmp < min) min = tmp;
    }
    cost[from][to] = min;
    return cost[from][to];
  }
}

int main(){
  int n;
  scanf("%d", &n);

  int p[N];
  int cost[N][N];
  for(int i = 0; i < n; ++i){
    int a, b;
    scanf("%d %d", &a, &b);
    p[i] = a;
    p[i+1] = b;
  }
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j)
      cost[i][j] = -1;
  }

  printf("%d", mat_chain_product(cost, 0, n-1, p));
}

#include <stdio.h>

int fib(int *dp, int n){
  if(n == 1 || n == 0) return dp[n] = 1;
  else if(dp[n] != -1) return dp[n];
  else return dp[n] = fib(dp, n-1) + fib(dp, n-2);
}

int main(){
  int n, i;
  int dp[50];

  for(int i = 0; i < 50; ++i) dp[i] = -1;

  scanf("%d", &n);
  printf("%d\n", fib(dp, n));
}

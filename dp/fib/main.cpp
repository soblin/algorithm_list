#include <iostream>

int fib(int *dp, int n){
  if (n == 0 or n == 1) return dp[n] = 1;
  else if (dp[n] != -1) return dp[n];
  else return dp[n] = fib(dp, n-1) + fib(dp, n-2);
}

int main(){
  int dp[50];
  for(int i = 0; i < sizeof(dp) / sizeof(dp[0]); ++i){
    dp[i] = -1;
  }

  int n;
  std::cin >> n;
  std::cout << fib(dp, n) << std::endl;
}

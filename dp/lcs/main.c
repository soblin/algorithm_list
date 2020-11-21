#include <stdio.h>
#include <string.h>

const int N = 100;

int max(int a, int b){
  if (a > b) return a;
  else return b;
}

int lcs(const char *str1_, const char *str2_){
  int m = strlen(str1_);
  int n = strlen(str2_);
  
  char str1[N]; str1[0] = ' ';
  char str2[N]; str2[0] = ' ';

  for(int i = 0; i < m; ++i) str1[i+1] = str1_[i];
  for(int i = 0; i < n; ++i) str2[i+1] = str2_[i];
  
  int c[N+1][N+1];

  for(int i = 0; i < m; ++i) c[i][0] = 0;
  for(int i = 0; i < n; ++i) c[0][i] = 0;

  for(int i = 1; i <= m; ++i){
    for(int j = 1; j <= n; ++j){
      if (str1[i] == str2[j]) c[i][j] = c[i-1][j-1] + 1;
      else c[i][j] = max(c[i-1][j], c[i][j-1]);
    }
  }

  return c[m][n];
}

int main(){
  char str1[100], str2[100];

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%s\n", str1);
    scanf("%s\n", str2);
    //    printf("compring %s and %s\n", str1, str2);
    printf("%d\n", lcs(str1, str2));
  }
}

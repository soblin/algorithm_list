#include <stdio.h>

int main(int argc, char **argv){
  int n;
  scanf("%d", &n);

  int mat[100][100];
  for(int i = 0; i < 100; ++i){
    for(int j = 0; j < 100; ++j)
      mat[i][j] = 0;
  }
  
  for(int i = 0; i < n; ++i){
    int u, k;
    scanf("%d %d", &u, &k);
    for(int j = 0; j < k; ++j){
      int v;
      scanf("%d", &v);
      mat[u-1][v-1] = 1;
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j)
      printf(" %d", mat[i][j]);

    printf("\n");
  }
}

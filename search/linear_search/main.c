#include <stdio.h>

int main(int argc, char **argv){
  int n, q;
  int S[100], T[100];
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d ", &S[i]);
  }
  scanf("%d", &q);
  for(int i = 0; i < q; ++i){
    scanf("%d", &T[i]);
  }

  int ret = 0;
  for(int i = 0; i < q; ++i){
    int val = T[i];
    for(int j = 0; j < n; ++j){
      ret += (S[j] == val);
    }
  }

  printf("%d", ret);
}

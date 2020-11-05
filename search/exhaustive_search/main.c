#include <stdio.h>
#include <stdbool.h>

bool check(const int *array, const int to, const int query){
  // use array[0-to]
  if (query == array[to])
    return true;
  if (to == 0)
    return false;
  
  return check(array, to-1, query) || check(array, to-1, query-array[to]);
}

int main(int argc, char **argv){
  int n, q;
  int A[100], m[100];
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d ", &A[i]);
  }
  scanf("%d", &q);
  for(int i = 0; i < q; ++i){
    scanf("%d", &m[i]);
  }

  for(int i = 0; i < q; ++i){
    int query = m[i];
    if(check(A, n-1, query)){
      printf("yes\n");
    }
    else{
      printf("no\n");
    }
  }
}

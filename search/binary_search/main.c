#include <stdio.h>

int binary_search(const int *array, const int size, const int query){
  // search in [left, right) <== `right` is not included
  int left = 0;
  int right = size;
  while(left < right){
    int mid = (left + right) / 2;
    if (array[mid] == query)
      return 1;
    else if (query < array[mid])
      right = mid;
    else
      left = mid + 1;
  }

  return 0;
}

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
    int query = T[i];
    ret += binary_search(S, n, query);
  }
  printf("%d", ret);
}

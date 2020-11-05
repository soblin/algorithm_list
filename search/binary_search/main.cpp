#include <iostream>

int binary_search(const int *array, const int size, const int query){
  // search [left, right)
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
  std::cin >> n;
  for(int i = 0; i<n; ++i){
    std::cin >> S[i];
  }
  std::cin >> q;
  for(int i = 0; i<q; ++i){
    std::cin >> T[i];
  }

  int ret = 0;

  for(int i = 0; i < q; ++i){
    int query = T[i];
    ret += binary_search(S, n, query);
  }
  std::cout << ret;
}

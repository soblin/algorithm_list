#include <iostream>

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
    int val = T[i];
    for(int j = 0; j < n; ++j){
      ret += (S[j] == val);
    }
  }

  std::cout << ret;
}

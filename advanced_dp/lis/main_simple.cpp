#include <cstdio>
#include <iostream>
#include <vector>
#define N 100
#define INFTY 100000

using namespace std;

int main() {
  int n_;
  cin >> n_;
  const int n = n_;

  vector<int> A;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  vector<int> L;
  L.resize(n + 1);
  vector<int> P;
  P.resize(n);
  
  L[0] = 0;
  L[1] = 1;
  P[0] = -1;
  int opt_ind_lis = 0;
  for (int i = 1; i < n; ++i) {
    int k = 0; // dummy previous LIS element of A[i]

    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i] and L[j+1] > L[k])
        k = j+1;
    }

    L[i+1] = L[k] + 1;
    if (L[opt_ind_lis] < L[i+1])
      opt_ind_lis = i+1;
    P[i] = k-1;
  }

  cout << L[opt_ind_lis] << endl;
}

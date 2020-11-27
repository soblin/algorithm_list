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
  A.push_back(-1);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  vector<int> L;
  L.resize(n + 1);
  vector<int> P;
  P.resize(n + 1);

  A[0] = -1;
  L[0] = 0;
  P[0] = -1;
  for (int i = 1; i <= n; ++i) {
    int k = 0; // dummy previous LIS element of A[i]

    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i] and L[j] > L[k])
        k = j;
    }

    L[i] = L[k] + 1;
    P[i] = k;
  }

  cout << L[n] << endl;
}

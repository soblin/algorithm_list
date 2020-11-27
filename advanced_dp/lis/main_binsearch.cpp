#include <algorithm>
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
  L[0] = A[0];
  int length = 1;
  for (int i = 1; i < n; ++i) {
    if (A[i] > L[length - 1])
      L[length++] = A[i];
    else {
      auto start = L.begin();
      auto end = L.begin();
      advance(end, length - 1);
      *lower_bound(start, end, A[i]) = A[i];
    }
  }
  cout << length << endl;
}

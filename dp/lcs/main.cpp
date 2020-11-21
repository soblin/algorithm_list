#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static const int N = 1000;

int lcs(string str1, string str2){
  int c[N+1][N+1];

  int m = str1.size();
  int n = str2.size();

  int maxl = 0;

  str1 = ' ' + str1;
  str2 = ' ' + str2;

  for(int i = 0; i <= m; ++i) c[i][0] = 0;
  for(int i = 0; i <= n; ++i) c[0][i] = 0;

  for(int i = 1; i <= m; ++i){
    for(int j = 1; j <= n; ++j){
      if(str1[i] == str2[j]){
        c[i][j] = c[i-1][j-1] + 1;
      }
      else{
        c[i][j] = max(c[i][j-1], c[i-1][j]);
      }
      maxl = max(maxl, c[i][j]);
    }
  }

  return maxl;
}

int main(){
  string str1, str2;
  int n; cin >> n;

  for(int i = 0; i < n; ++i){
    cin >> str1 >> str2;
    cout << lcs(str1, str2) << endl;
  }
}

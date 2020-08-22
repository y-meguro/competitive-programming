#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int K;
  cin >> K;

  // メモを作る
  vector<vector<int>> g(201, vector<int>(201));
  for (int i = 0; i <= 200; i++) {
    for (int j = 0; j <= 200; j++) {
      if (i == 0 || j == 0) {
        g.at(i).at(j) = 0;
      } else {
        g.at(i).at(j) = __gcd(i, j);
      }
    }
  }

  // 和を求める
  ll ans = 0;
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= K; j++) {
      int x = g.at(i).at(j);
      for (int k = 0; k <= K; k++) {
        ans += g.at(x).at(k);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
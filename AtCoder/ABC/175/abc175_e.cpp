#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)

int items[3001][3001];
ll dp[3001][3001][4];

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  rep(i, K) {
    int r, c, v;
    cin >> r >> c >> v;
    items[r-1][c-1] = v;
  }

  rep(i, R) rep(j, C) {
    for (int k = 2; k >= 0; --k) {
      chmax(dp[i][j][k+1], dp[i][j][k] + items[i][j]);
    }
    rep(k, 4) {
      chmax(dp[i][j+1][k], dp[i][j][k]);
      chmax(dp[i+1][j][0], dp[i][j][k]);
    }
  }

  ll ans = 0;
  rep(k, 4) chmax(ans, dp[R-1][C-1][k]);
  cout << ans << endl;
  return 0;
}
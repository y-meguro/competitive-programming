#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[101][4][2];

int main() {
  string N;
  int K;
  cin >> N >> K;
  int L = N.size();
  dp[0][0][0] = 1;

  // dp[i][j][0] には i 桁目まで調べて、0 以外の数字を j 回使って、N とそこまでの桁が一致しているものの総数が入る
  // dp[i][j][1] には i 桁目まで調べて、0 以外の数字を j 回使って、N より小さいことが確定しているものの総数が入る
  rep(i, L) rep(j, 4) rep(l, 2) {
    int nd = N[i] - '0'; // 次の桁
    rep(d, 10) {
      int ni = i + 1;
      int nj = j;
      int nl = l;
      if (d > 0) nj++;
      if (nj > K) continue;
      if (l == 0) {
        if (d > nd) continue;
        if (d < nd) nl = 1;
      }
      dp[ni][nj][nl] += dp[i][j][l];
    }
  }

  ll ans = dp[L][K][0] + dp[L][K][1];
  cout << ans << endl;
  return 0;
}
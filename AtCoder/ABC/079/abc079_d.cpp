#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> dp(10, vector<int>(10));
  rep(i, 10) {
    rep(j, 10) {
      cin >> dp.at(i).at(j);
    }
    dp.at(i).at(i) = 0;
  }

  rep(k, 10) {
    rep(i, 10) {
      rep(j, 10) {
        dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }

  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      int c;
      cin >> c;

      if (c == -1) continue;
      ans += dp.at(c).at(1);
    }
  }
  cout << ans << endl;
  return 0;
}
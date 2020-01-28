#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, W;
  cin >> N >> W;

  vector<ll> w(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> w.at(i) >> v.at(i);
  }

  vector<ll> dp(W + 1, -1);
  dp.at(0) = 0;
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= 0; j--) {
      if (j - w.at(i) >= 0) {
        dp.at(j) = max(dp.at(j), dp.at(j - w.at(i)) + v.at(i));
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i <= W; i++) {
    if (dp.at(i) > ans) ans = dp.at(i);
  }

  cout << ans << endl;

  return 0;
}

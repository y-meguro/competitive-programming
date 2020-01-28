#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  ll W;
  cin >> N >> W;

  vector<ll> w(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> w.at(i) >> v.at(i);
  }

  vector<ll> dp(N * 1000 + 1, W + 1);
  dp.at(0) = 0;
  for (int i = 0; i < N; i++) {
    for (int j = N * 1000; j >= 0; j--) {
      if (0 <= j - v.at(i) && j - v.at(i) <= N * 1000) {
        dp.at(j) = min(dp.at(j), dp.at(j - v.at(i)) + w.at(i));
      }
    }
  }

  ll ans;
  for (int i = N * 1000; i >= 0; i--) {
    if (dp.at(i) != W + 1) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}

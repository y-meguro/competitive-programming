#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  ll K;
  cin >> N >> K;

  vector<int> a(N + 1), suma(N + 1);
  a.at(0) = 0;
  suma.at(0) = 0;
  for (int i = 0; i < N; i++) {
    cin >> a.at(i + 1);
    suma.at(i + 1) = suma.at(i) + a.at(i + 1);
  }
  if (suma.at(N) == K) {
    cout << 1 << endl;
    return 0;
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, LLONG_MAX));
  dp.at(0).at(0) = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
      if (dp.at(i).at(j) > K) continue;
      dp.at(i + 1).at(j) = min(dp.at(i + 1).at(j), dp.at(i).at(j));

      ll wins;
      if (i == 0) {
        wins = 1;
      } else {
        wins = dp.at(i).at(j) * suma.at(i + 1) / suma.at(i) + 1;
      }

      if (wins - dp.at(i).at(j) <= a.at(i + 1)) {
        dp.at(i + 1).at(j + 1) = min(dp.at(i + 1).at(j + 1), wins);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= N; i++) {
    if (dp.at(N).at(i) <= K) ans = i;
  }

  cout << ans << endl;

  return 0;
}

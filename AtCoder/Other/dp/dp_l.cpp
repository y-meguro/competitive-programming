#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  rep(i, N) cin >> a.at(i);

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
  rep(i, N) dp.at(i).at(i) = 0;

  for (int l = 1; l <= N; l++) {
    for (int i = 0; i + l <= N; i++) {
      int j = i + l;
      if ((N - l) % 2 == 0) {
        dp.at(i).at(j) = max(dp.at(i + 1).at(j) + a.at(i), dp.at(i).at(j - 1) + a.at(j - 1));
      } else {
        dp.at(i).at(j) = min(dp.at(i + 1).at(j) - a.at(i), dp.at(i).at(j - 1) - a.at(j - 1));
      }
    }
  }
  cout << dp.at(0).at(N) << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  if (K >= N) {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }

  sort(H.begin(), H.end());

  ll ans = 0LL;
  for (int i = 0; i < N - K; i++) {
    ans += H.at(i);
  }

  cout << ans << endl;

  return 0;
}

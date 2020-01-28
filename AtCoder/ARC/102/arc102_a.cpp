#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  ll x = N / K;
  ll ans = x * x * x;

  if (K % 2 == 0) {
    ll y = (N + K / 2) / K;
    ans += y * y * y;
  }

  cout << ans << endl;

  return 0;
}

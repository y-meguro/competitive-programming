#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }

  ll ans = 1;
  for (int i = 0; i < N; i++) {
    ll gdc = __gcd(ans, T.at(i));
    ans = ans / gdc * T.at(i);
  }

  cout << ans << endl;

  return 0;
}

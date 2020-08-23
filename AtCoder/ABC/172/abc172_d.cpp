#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  auto f = [&](ll x) {
    return x * (x + 1) / 2;
  };

  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    ans += i * f(n / i);
  }

  cout << ans << endl;
  return 0;
}
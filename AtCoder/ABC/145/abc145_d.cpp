#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;

ll modinv(ll a, ll m) {
  ll b = m;
  ll u = 1;
  ll v = 0;

  while (b > 0) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }

  u %= m;
  if (u < 0) u += m;
  return u;
}

int main() {
  int X, Y;
  cin >> X >> Y;

  if (X * 2 - Y < 0 || Y * 2 - X < 0 || (2 * X - Y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  ll a = (2 * Y - X) / 3;
  ll b = (2 * X - Y) / 3;

  ll ans = 1;
  for (int i = 0; i < a; i++) {
    ans *= a + b - i;
    ans %= mod;
  }

  for (int i = 1; i <= a; i++) {
    ans *= modinv(i, mod);
    ans %= mod;
  }

  cout << ans << endl;
  return 0;
}

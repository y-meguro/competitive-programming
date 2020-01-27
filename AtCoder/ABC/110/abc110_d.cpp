#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

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
  int N;
  ll M;
  cin >> N >> M;

  map<int, ll> m;
  ll x = M;
  ll j = 2;
  while (j <= x) {
    if (x % j == 0) {
      x /= j;
      m[j]++;
    } else {
      j++;
    }
  }

  ll ans = 1;
  for (auto e : m) {
    int p = e.second;
    for (int j = 1; j <= p; j++) {
      ans = ans * ((p + N - j) % mod) % mod;
      ans = ans * modinv(j, mod) % mod;
    }
  }

  cout << ans << endl;

  return 0;
}

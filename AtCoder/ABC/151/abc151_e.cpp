#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
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
  int N, K;
  cin >> N >> K;

  vector<ll> A(N);
  rep(i, N) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());

  vector<ll> c(N + 1, 0);
  c.at(K - 1) = 1;
  for(int i = 1; i <= N; i++) {
    if (i <= K - 1) continue;
    int x = i - (K - 1);
    c.at(i) = (c.at(i - 1) * i % mod) * modinv(x, mod) % mod;
  }

  ll ans = 0;
  rep(i, N) {
    if (i >= K - 1) {
      ans += c.at(i) * A.at(i) % mod;
      ans %= mod;
    }
    if (N - i - 1 >= K - 1) {
      ans -= c.at(N - i - 1) * A.at(i) % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
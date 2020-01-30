#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int mod = 1e9 + 7;

vector<int> f(1000001, 0);

void getf(int a) {
  for (int i = 2; i * i <= a; i++) {
    int cnt = 0;
    while (a % i == 0) {
      cnt++;
      a /= i;
    }
    if (cnt > f.at(i)) f.at(i) = cnt;
  }
  if (a > 1) f.at(a) = max(f.at(a), 1);
}

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
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    getf(A.at(i));
  }

  ll lcm = 1LL;
  for (int i = 2; i <= 1000000; i++) {
    if (f.at(i) == 0) continue;
    lcm = (lcm * (ll)pow(i, f.at(i)) % mod) % mod;
  }

  ll ans = 0LL;
  for (int i = 0; i < N; i++) {
    ans = (ans + lcm * modinv(A.at(i), mod) % mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
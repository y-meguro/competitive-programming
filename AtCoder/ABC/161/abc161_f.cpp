#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> enumDivisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (i * i != n) res.push_back(n / i);
  }
  return res;
}

int main() {
  ll n;
  cin >> n;

  // n の約数について条件を調べる
  int ans = 0;
  for (ll x : enumDivisor(n)) {
    if (x == 1) continue;
    ll tmp = n;
    while (tmp % x == 0) tmp /= x;
    if (tmp % x == 1) ans++;
  }

  // n - 1 の約数はすべて条件を満たすので足す。ただし 1 は除く
  ans += enumDivisor(n - 1).size() - 1;

  cout << ans << endl;
  return 0;
}
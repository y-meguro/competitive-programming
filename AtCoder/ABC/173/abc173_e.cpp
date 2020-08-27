#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll mod = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> pos, neg;
  rep(i, n) {
    cin >> a.at(i);
    if (a.at(i) < 0) neg.push_back(a.at(i));
    else pos.push_back(a.at(i));
  }

  int posSize = pos.size();
  int negSize = neg.size();
  bool ok = false; // 選び方によって、答えを正にすることができる場合 true
  if (posSize > 0) {
    if (n == k) ok = (negSize % 2 == 0);
    else ok = true;
  } else {
    ok = (k % 2 == 0);
  }

  ll ans = 1;
  if (!ok) {
    sort(a.begin(), a.end(), [](int x, int y) {
      return abs(x) < abs(y);
    });
    rep(i, k) ans = ans * a.at(i) % mod;
    ans = mod + ans;
  } else {
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    if (k % 2 == 1) {
      ans = ans * pos.back() % mod;
      pos.pop_back();
    }

    vector<ll> p;
    while (pos.size() >= 2) {
      ll x = pos.back(); pos.pop_back();
      x *= pos.back(); pos.pop_back();
      p.push_back(x);
    }
    while (neg.size() >= 2) {
      ll x = neg.back(); neg.pop_back();
      x *= neg.back(); neg.pop_back();
      p.push_back(x);
    }
    sort(p.rbegin(), p.rend());
    rep(i, k/2) ans = ans * (p.at(i) % mod) % mod;
  }

  cout << ans << endl;
  return 0;
}
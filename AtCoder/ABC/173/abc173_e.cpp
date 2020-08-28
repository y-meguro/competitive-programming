#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll mod = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  vector<int> pos, neg;
  rep(i, n) {
    cin >> a.at(i);
    if (a.at(i) < 0) neg.push_back(a.at(i));
    else pos.push_back(a.at(i));
  }

  // 正にできる組み合わせがあるか調べる
  bool ok = true;
  int posSize = pos.size();
  int negSize = neg.size();
  if (posSize == 0) {
    ok = (k % 2 == 0);
  } else {
    if (n == k) ok = (negSize % 2 == 0);
  }

  ll ans = 1;
  if (!ok) {
    // できない場合は絶対値の小さい順に取る
    sort(a.begin(), a.end(), [](int x, int y) {
      return abs(x) < abs(y);
    });
    rep(i, k) ans = ans * a.at(i) % mod;
    ans = mod + ans;
  } else {
    // できる場合は積を大きくできる組み合わせを選ぶ
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    if (k % 2 == 1) {
      ans = ans * pos.back() % mod;
      pos.pop_back();
    }

    vector<ll> p;
    while (pos.size() > 1) {
      ll tmp = pos.back(); pos.pop_back();
      tmp *= pos.back(); pos.pop_back();
      p.push_back(tmp);
    }
    while (neg.size() > 1) {
      ll tmp = neg.back(); neg.pop_back();
      tmp *= neg.back(); neg.pop_back();
      p.push_back(tmp);
    }
    sort(p.rbegin(), p.rend());
    rep(i, k/2) ans = ans * (p.at(i) % mod) % mod;
  }

  cout << ans << endl;
  return 0;
}
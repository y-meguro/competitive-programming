#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n, 0), f(n, 0);
  int sum = 0;
  rep(i, n) {
    cin >> a.at(i);
    sum += a.at(i);
  }

  rep(i, n) cin >> f.at(i);
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());

  ll l = -1, r = 1e13; // lは絶対にダメな値、rは絶対にOKな値にする
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    ll cnt = 0;
    rep(i, n) {
      cnt += max(0ll, a.at(i) - mid / f.at(i)); // a.at(i) - mid / f.at(i) が負になる場合ある
    }
    if (cnt <= k) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r << endl;
  return 0;
}
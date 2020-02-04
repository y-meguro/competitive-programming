#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N, K;
  cin >> N >> K;

  vector<ll> a(N), b(N);
  rep(i, N) cin >> a.at(i);
  rep(i, N) cin >> b.at(i);
  sort(a.begin(), a.end());

  ll l = 0;
  ll r = 1e18 + 1;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    ll sum = 0;
    rep(i, N) {
      ll key = mid / b.at(i);
      sum += upper_bound(a.begin(), a.end(), key) - a.begin();
    }
    if (sum < K) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << r << endl;
  return 0;
}
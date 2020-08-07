#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N, K;
  cin >> N >> K;

  vector<ll> A(N);
  rep(i, N) cin >> A.at(i);
  sort(A.begin(), A.end());

  ll l = -1e18 - 1;
  ll r = 1e18 + 1;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    ll sum = 0;
    rep(i, N) {
      if (A.at(i) > 0) sum += lower_bound(A.begin(), A.end(), (long double) mid / A.at(i)) - A.begin();
      if (A.at(i) < 0) sum += N - (upper_bound(A.begin(), A.end(), (long double) mid / A.at(i)) - A.begin());
      if (A.at(i) == 0) {
        if (mid > 0) sum += N;
      }
      if (A.at(i) * A.at(i) < mid) sum--;
    }
    if (sum / 2 < K) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
  return 0;
}
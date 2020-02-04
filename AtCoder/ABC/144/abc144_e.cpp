#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  ll K;
  cin >> N >> K;

  vector<int> A(N);
  rep(i, N) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());

  vector<ll> F(N);
  rep(i, N) {
    cin >> F.at(i);
  }
  sort(F.rbegin(), F.rend());

  ll l = 0;
  ll r = 1e12 + 1;
  ll ans = 0;

  while (l <= r) {
    ll mid = (l + r) / 2;
    ll sum = K;
    rep(i, N) {
      if (mid / F.at(i) < A.at(i)) {
        sum -= A.at(i) - mid / F.at(i);
      }
    }
    if (sum < 0) {
      l = mid + 1;
    } else {
      ans = mid;
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
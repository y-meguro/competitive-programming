#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  if (x < 0) x = -x;

  ll num = x / d;
  ll r = x % d;
  if (r > abs(r - d)) {
    ++num;
    r = abs(r - d);
  }

  ll ans;
  if (num < k) {
    if ((k - num) % 2 == 0) {
      ans = r;
    } else {
      ans = d - r;
    }
  } else {
    ans = x - k * d;
  }

  cout << ans << endl;
  return 0;
}
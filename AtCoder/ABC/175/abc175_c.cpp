#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);

  ll ans;
  ll num = x / d;
  if (num > k) {
    ans = x - k * d;
  } else {
    k -= num;
    x -= num * d;
    if (k % 2 == 0) ans = x;
    else ans = abs(x - d);
  }

  cout << ans << endl;
  return 0;
}
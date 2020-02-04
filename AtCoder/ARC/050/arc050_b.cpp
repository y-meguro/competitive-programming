#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll R, B, x, y;
  cin >> R >> B >> x >> y;

  ll l = 0;
  ll r = 1e18 + 1;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    bool isValid = false;
    if (R >= mid && B >= mid && (R - mid) / (x - 1) + (B - mid) / (y - 1) >= mid) {
      isValid = true;
    }
    if (isValid) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
  return 0;
}
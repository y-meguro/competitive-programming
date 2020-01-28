#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, X;
  cin >> N >> X;

  ll ans = N;
  ll a = max(N - X, X);
  ll b = min(N - X, X);

  while (true) {
    ans += a / b * 2 * b;
    if (a % b == 0) {
      ans -= b;
      break;
    } else {
      ll tmp = a;
      a = b;
      b = tmp % b;
    }
  }

  cout << ans << endl;

  return 0;
}

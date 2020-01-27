#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll A, B;
  cin >> A >> B;

  ll p = __gcd(A, B);
  ll ans = 1;
  for (int i = 2; i <= sqrt(p); i++) {
    if (p % i == 0) {
      ans++;
      while (p % i == 0) {
        p /= i;
      }
    }
  }
  if (p > 1) ans++; // 割り切れていない場合はもう1つある

  cout << ans << endl;

  return 0;
}

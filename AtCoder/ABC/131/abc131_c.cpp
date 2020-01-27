#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  ll gcd = __gcd(C, D);

  ll ans = B - A + 1;
  ans -= (B / C - (A - 1) / C) + (B / D - (A - 1) / D) - (B / (C / gcd * D) - (A - 1) / (C / gcd * D));

  cout << ans << endl;

  return 0;
}

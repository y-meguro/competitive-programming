#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N;
  cin >> N;

  ll x = N / 3;
  ll y = N / 5;
  ll z = N / 15;

  ll ans = 0;
  ans = N * (N + 1) / 2 - (3 * x * (x + 1) / 2) - (5 * y * (y + 1) / 2) + (15 * z * (z + 1) / 2);

  cout << ans << endl;
  return 0;
}
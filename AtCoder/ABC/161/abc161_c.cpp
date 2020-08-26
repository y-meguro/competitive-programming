#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;

  ll x = n % k;
  ll y = -(x - k);
  ll ans = (x < y) ? x : y;
  cout << ans << endl;
  return 0;
}
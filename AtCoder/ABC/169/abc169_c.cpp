#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll A, B;
  double x;
  cin >> A >> x;
  B = x * 100 + 0.5;

  ll ans = A * B / 100;
  cout << ans << endl;
  return 0;
}
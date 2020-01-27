#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll h) {
  if (h == 1) {
    return 1;
  }
  return solve(h/2) * 2 + 1;
}

int main() {
  ll H;
  cin >> H;

  cout << solve(H) << endl;

  return 0;
}

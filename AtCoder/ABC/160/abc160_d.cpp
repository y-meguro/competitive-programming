#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--; y--;

  vector<int> ans(n, 0);
  rep(i, n) rep(j, n) {
    if (i >= j) continue;
    int d = min(j - i, abs(x - i) + abs(y - j) + 1);
    ans.at(d)++;
  }

  for (int i = 1; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
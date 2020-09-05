#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l.at(i);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = l.at(i);
    for (int j = i + 1; j < n; ++j) {
      int y = l.at(j);
      for (int k = j + 1; k < n; ++k) {
        int z = l.at(k);
        if (x == y || y == z || z == x) continue;
        if (x + y <= z || y + z <= x || z + x <= y) continue;
        ++ans;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
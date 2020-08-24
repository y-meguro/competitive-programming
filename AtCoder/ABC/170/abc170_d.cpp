#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep(i, n) cin >> a.at(i);

  int m = 1e6 + 1;
  vector<int> cnt(m, 0);
  for (int x : a) {
    if (cnt.at(x) != 0) {
      cnt.at(x) = 2;
      continue;
    }
    for (int j = x; j < m; j += x) {
      cnt.at(j)++;
    }
  }

  int ans = 0;
  for (int x : a) {
    if (cnt.at(x) == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}
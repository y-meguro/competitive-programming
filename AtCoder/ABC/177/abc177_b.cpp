#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  int ans = 1e9;
  for (int i = 0; i <= n - m; i++) {
    int tmp = 0;
    for (int j = 0; j < m; j++) {
      if (s.at(i + j) != t.at(j)) tmp++;
    }
    ans = min(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
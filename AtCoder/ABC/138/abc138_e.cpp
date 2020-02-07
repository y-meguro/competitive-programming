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

  vector<vector<int>> sPos(26);
  rep(i, n) {
    int c = s.at(i) - 'a';
    sPos.at(c).push_back(i);
  }
  rep(i, n) {
    int c = s.at(i) - 'a';
    sPos.at(c).push_back(i + n);
  }

  ll ans = 0;
  int pos = 0;
  rep(i, m) {
    int c = t.at(i) - 'a';
    if (sPos.at(c).empty()) {
      cout << -1 << endl;
      return 0;
    } else {
      pos = *lower_bound(sPos.at(c).begin(), sPos.at(c).end(), pos) + 1;
      if (pos >= n) {
        ans += n;
        pos -= n;
      }
    }
  }
  ans += pos;
  cout << ans << endl;
  return 0;
}
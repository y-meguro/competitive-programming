#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int m = 2019;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());

  // 余りをカウントする
  ll ans = 0;
  int tot = 0, x = 1;
  vector<int> cnt(m, 0);
  cnt.at(0) = 1;
  for (int i = 0; i < (int)s.size(); i++) {
    tot += (s.at(i) - '0') * x;
    tot %= m;
    ans += cnt.at(tot);
    cnt.at(tot)++;
    x = x * 10 % m;
  }

  cout << ans << endl;
  return 0;
}
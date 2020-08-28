#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll mod = 1e9 + 7;

int main() {
  int m = 2019;
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());

  int x = 1, tot = 0;
  ll ans = 0;
  vector<int> cnt(m, 0); // 余りの数ごとに何個あるか数えておく
  cnt.at(0) = 1;
  rep(i, n) {
    tot += (s.at(i) - '0') * x;
    tot %= m;
    ans += cnt.at(tot);
    cnt.at(tot)++;
    x = x * 10 % m;
  }

  cout << ans << endl;
  return 0;
}
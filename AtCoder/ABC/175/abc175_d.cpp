#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n), c(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  rep(i, n) cin >> c.at(i);

  ll ans = -1e18 - 1;
  rep(si, n) {
    // まず周期を求める
    int current = si;
    vector<int> s;
    ll tot = 0;
    while (1) {
      current = p.at(current);
      s.push_back(c.at(current));
      tot += c.at(current);
      if (current == si) break;
    }

    // 最大値を求める
    int l = s.size();
    ll t = 0;
    rep(i, l) {
      if (i + 1 > k) break;
      t += s.at(i);
      ll now = t;
      if (tot > 0) {
        ll loopNum = (k - i - 1) / l;
        now += tot * loopNum;
      }
      ans = max(ans, now);
    }
  }

  cout << ans << endl;
  return 0;
}
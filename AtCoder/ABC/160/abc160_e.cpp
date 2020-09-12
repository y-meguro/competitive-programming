#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a), q(b), r(c);
  rep(i, a) cin >> p.at(i);
  rep(i, b) cin >> q.at(i);
  rep(i, c) cin >> r.at(i);
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  sort(r.rbegin(), r.rend());

  ll ans = 0;
  vector<int> s;
  rep(i, x) {
    s.push_back(p.at(i));
    ans += p.at(i);
  }
  rep(i, y) {
    s.push_back(q.at(i));
    ans += q.at(i);
  }
  sort(s.begin(), s.end());

  int n = min((int)s.size(), c);
  for (int i = 0; i < n; i++) {
    if (s.at(i) < r.at(i)) {
      ans += r.at(i) - s.at(i);
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
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

  vector<int> s;
  rep(i, x) s.push_back(p.at(i));
  rep(i, y) s.push_back(q.at(i));
  rep(i, c) s.push_back(r.at(i));
  sort(s.rbegin(), s.rend());

  ll ans = 0;
  rep(i, x + y) ans += s.at(i);
  cout << ans << endl;
  return 0;
}
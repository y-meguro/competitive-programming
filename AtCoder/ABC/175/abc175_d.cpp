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
    // 周期を求める
    int cycle = 0;
    ll loopPoint = 0;
    int current = si;
    while (true) {
      int next = p.at(current);
      loopPoint += c.at(next);
      cycle++;
      if (si == next) break;
      current = next;
    }

    // 最大値を求める
    ll tmp = 0;
    current = si;
    rep(i, cycle) {
      if (i >= k) break;
      int next = p.at(current);
      tmp += c.at(next);
      ll sum = tmp;
      if (loopPoint > 0) {
        sum += (k - i - 1) / cycle * loopPoint;
      }
      ans = max(ans, sum);
      current = next;
    }
  }

  cout << ans << endl;
  return 0;
}
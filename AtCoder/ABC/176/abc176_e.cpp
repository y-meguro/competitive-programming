#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int H, W, M;
  cin >> H >> W >> M;
  map<P, bool> mp;
  vector<int> r(H, 0);
  vector<int> c(W, 0);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    mp[{x, y}] = true;
    r.at(x)++;
    c.at(y)++;
  }

  int maxR = 0;
  rep(i, H) {
    if (r.at(i) > maxR) maxR = r.at(i);
  }
  vector<int> list1;
  rep(i, H) {
    if (r.at(i) == maxR) list1.push_back(i);
  }

  int maxC = 0;
  rep(i, W) {
    if (c.at(i) > maxC) maxC = c.at(i);
  }
  vector<int> list2;
  rep(i, W) {
    if (c.at(i) == maxC) list2.push_back(i);
  }

  int ans = maxR + maxC;
  for (auto x : list1) {
    for (auto y : list2) {
      if (!mp.count({x, y})) {
        cout << ans << endl;
        return 0;
      }
    }
  }

  cout << ans - 1 << endl;
  return 0;
}
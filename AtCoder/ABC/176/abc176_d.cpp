#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w, ch, cw, dh, dw;
  cin >> h >> w >> ch >> cw >> dh >> dw;
  ch--; cw--; dh--; dw--;
  vector<string> s(h);
  rep(i, h) {
    cin >> s.at(i);
  }

  vector<vector<int>> dp(h, vector<int>(w, 1e9));
  dp.at(ch).at(cw) = 0;
  deque<P> dq;
  dq.emplace_front(ch, cw);
  while (dq.size()) {
    P p = dq.front();
    dq.pop_front();
    int r = p.first, c = p.second;

    // 歩いて移動
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    rep(i, 4) {
      int nr = r + dr.at(i);
      int nc = c + dc.at(i);
      if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
      if (s.at(nr).at(nc) == '#') continue;
      if (dp.at(nr).at(nc) > dp.at(r).at(c)) {
        dp.at(nr).at(nc) = dp.at(r).at(c);
        dq.emplace_front(nr, nc);
      }
    }

    // ワープで移動
    rep(i, 5) {
      rep(j, 5) {
        int nr = r - 2 + i;
        int nc = c - 2 + j;
        if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
        if (s.at(nr).at(nc) == '#') continue;
        if (dp.at(nr).at(nc) > dp.at(r).at(c) + 1) {
          dp.at(nr).at(nc) = dp.at(r).at(c) + 1;
          dq.emplace_back(nr, nc);
        }
      }
    }
  }

  cout << (dp.at(dh).at(dw) == 1e9 ? -1 : dp.at(dh).at(dw)) << endl;
  return 0;
}
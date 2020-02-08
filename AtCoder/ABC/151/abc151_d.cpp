#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> maze(H, vector<char>(W));

  rep(i, H) {
    rep(j, W) {
      cin >> maze.at(i).at(j);
    }
  }

  int ans = 0;
  auto bfs = [&](int sx, int sy) {
    if (maze.at(sx).at(sy) == '#') return;
    vector<vector<int>> d(H, vector<int>(W, -1));
    d.at(sx).at(sy) = 0;
    queue<P> q;
    q.push(P(sx, sy));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      rep(i, 4) {
        int nx = x + dx.at(i);
        int ny = y + dy.at(i);
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (maze.at(nx).at(ny) == '#' || d.at(nx).at(ny) != -1) continue;
        d.at(nx).at(ny) = d.at(x).at(y) + 1;
        ans = max(ans, d.at(nx).at(ny));
        q.emplace(nx, ny);
      }
    }
  };

  rep(i, H) {
    rep(j, W) {
      bfs(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}
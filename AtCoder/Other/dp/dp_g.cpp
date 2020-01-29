#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> xy;
vector<int> dp;
vector<bool> reached;

void dfs (int u) {
  if (reached.at(u)) return;
  reached.at(u) = true;
  for (int v : xy.at(u)) {
    dfs(v);
    dp.at(u) = max(dp.at(u), dp.at(v) + 1);
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  xy.resize(N);
  dp.resize(N, 0);
  reached.resize(N, false);

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    xy.at(x).push_back(y);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    dfs(i);
    ans = max(ans, dp.at(i));
  }
  cout << ans << endl;
  return 0;
}
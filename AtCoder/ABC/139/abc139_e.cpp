#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> A;
vector<vector<int>> id;

int toId(int i, int j) {
  int a = i;
  int b = A.at(i).at(j); // 対戦相手
  if (a > b) swap(a, b);
  return id.at(a).at(b);
}

vector<vector<int>> G;
vector<int> dp;
vector<bool> reached;
vector<bool> completed;

int dfs(int v) {
  if (reached.at(v)) {
    if (!completed.at(v)) return -1;
    return dp.at(v);
  }
  reached.at(v) = true;
  dp.at(v) = 1;
  for (int u : G.at(v)) {
    int res = dfs(u);
    if (res == -1) return -1;
    dp.at(v) = max(dp.at(v), res + 1);
  }
  completed.at(v) = true;
  return dp.at(v);
}

int main() {
  int N;
  cin >> N;

  A.resize(N, vector<int>(N - 1));
  rep(i, N) {
    rep(j, N - 1) {
      cin >> A.at(i).at(j);
      A.at(i).at(j)--;
    }
  }

  // 試合用のidを作成、参加者を行と列に持つので、N * N の大きさが必要
  id.resize(N, vector<int>(N));
  int V = 0;
  rep(i, N) {
    rep(j, N) {
      if (i >= j) continue;
      id.at(i).at(j) = V++;
    }
  }

  int NUMV = N * (N - 1) / 2;
  G.resize(NUMV);
  dp.resize(NUMV);
  reached.resize(NUMV);
  completed.resize(NUMV);

  rep(i, N) {
    rep(j, N - 2) {
      G.at(toId(i, j + 1)).push_back(toId(i, j)); // 辺を逆順に張っておく
    }
  }

  int ans = 0;
  rep(i, NUMV) {
    int res = dfs(i);
    if (res == -1) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}
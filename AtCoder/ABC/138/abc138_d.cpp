#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> G;
vector<int> points;
vector<int> ans;

void dfs(int u, int p) {
  ans.at(u) += points.at(u);
  for (int v : G.at(u)) {
    if (v == p) continue;
    ans.at(v) += ans.at(u);
    dfs(v, u);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;

  G.resize(N);
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;

    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  points.resize(N, 0);
  rep(i, Q) {
    int p, x;
    cin >> p >> x;
    p--;

    points.at(p) += x;
  }

  ans.resize(N, 0);

  dfs(0, -1);
  rep(i, N) {
    cout << ans.at(i);
    if (i != N - 1) cout << " ";
  }
  cout << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> G;

void dfs(int current, int pre, vector<int> &d) {
  for (int next : G.at(current)) {
    if (next == pre) continue;
    d.at(next) = d.at(current) + 1;
    dfs(next, current, d);
  }
}

int main() {
  int N, u, v;
  cin >> N >> u >> v;
  u--; v--;

  G.resize(N);
  rep(i, N - 1) {
    int A, B;
    cin >> A >> B;
    A--; B--;

    G.at(A).push_back(B);
    G.at(B).push_back(A);
  }

  vector<int> du(N, 0); // uからの距離
  du.at(u) = 0;
  vector<int> dv(N, 0); // vからの距離
  dv.at(v) = 0;

  dfs(u, -1, du);
  dfs(v, -1, dv);

  int d = 0;
  rep(i, N) {
    if (du.at(i) >= dv.at(i)) continue;
    d = max(d, dv.at(i));
  }
  cout << d - 1 << endl;
  return 0;
}
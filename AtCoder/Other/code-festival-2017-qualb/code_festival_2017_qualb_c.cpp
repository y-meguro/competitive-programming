#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> color;

bool dfs(int v, int c) {
  color.at(v) = c;
  for (int x : g.at(v)) {
    if (color.at(x) == c) return false;
    if (color.at(x) == -1 && !dfs(x, 1 - c)) return false;
  }
  return true;
}

int main() {
  ll N, M;
  cin >> N >> M;

  g.resize(N);
  color.resize(N, -1);

  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;

    g.at(A).push_back(B);
    g.at(B).push_back(A);
  }

  bool isBipartite = dfs(0, 0);
  ll ans = 0;
  if (isBipartite) {
    ll whiteCnt = 0;
    for (int i = 0; i < N; i++) {
      if (color.at(i) == 0) whiteCnt++;
    }
    ans = whiteCnt * (N - whiteCnt) - M;
  } else {
    ans = N * (N - 1) / 2 - M;
  }

  cout << ans << endl;

  return 0;
}

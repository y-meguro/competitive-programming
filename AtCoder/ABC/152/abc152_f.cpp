#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge {
  int to, id;
  Edge(int to, int id): to(to), id(id) {}
};

vector<vector<Edge>> G;
vector<int> es;

bool dfs(int v, int g, int p) {
  if (v == g) return true;
  for (Edge e : G.at(v)) {
    if (e.to == p) continue;
    if (dfs(e.to, g, v)) {
      es.push_back(e.id);
      return true;
    }
  }
  return false;
}

int main() {
  int N, M;
  cin >> N;
  G.resize(N);

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;

    G.at(a).emplace_back(b, i);
    G.at(b).emplace_back(a, i);
  }

  cin >> M;
  vector<ll> eset(M);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    es.clear();
    dfs(u, v, -1);
    for (int e : es) {
      eset.at(i) |= 1ll << e;
    }
  }

  ll ans = 0;
  rep(i, 1 << M) { // パスの全組み合わせについて列挙
    ll mask = 0;
    rep(j, M) {
      if (i >> j & 1) mask |= eset.at(j); // maskで1が立っているものは、使用される辺のidと対応
    }
    int white = __builtin_popcountll(mask); // 白にすべき辺の本数
    ll now = 1ll << (N - 1 - white); // 2^(N - 1 - white)
    if (__builtin_popcountll(i) % 2 == 0) {
      ans += now;
    } else {
      ans -= now;
    }
  }
  cout << ans << endl;
  return 0;
}
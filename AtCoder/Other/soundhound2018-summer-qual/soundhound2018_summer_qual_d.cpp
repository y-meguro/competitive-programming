#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
const ll INF = 1e15;

struct Edge {
  int to;
  ll dist;
  Edge(int to, ll dist) : to(to), dist(dist) {}
};

struct Dijkstra {
  vector<ll> d;

  Dijkstra(int s, const vector<vector<Edge>> &g) {
    d.resize(g.size(), INF);
    d.at(s) = 0;

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));

    while (!que.empty()) {
      P p = que.top();
      que.pop();
      int v = p.second;
      if (d.at(v) < p.first) continue;

      for (Edge e : g.at(v)) {
        if (d.at(e.to) > d.at(v) + e.dist) {
          d.at(e.to) = d.at(v) + e.dist;
          que.push(P(d.at(e.to), e.to));
        }
      }
    }
  }  
};

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;
  t--;

  vector<vector<Edge>> G(n); // 円の計算用
  vector<vector<Edge>> G2(n); // スヌークの計算用

  for (int i = 0; i < m; i++) {
    int u, v;
    ll a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;

    G.at(u).push_back(Edge(v, a));
    G.at(v).push_back(Edge(u, a));
    G2.at(u).push_back(Edge(v, b));
    G2.at(v).push_back(Edge(u, b));
  }

  Dijkstra di(s, G);
  Dijkstra di2(t, G2);

  vector<ll> ans(n + 1, INF);
  for (int i = n - 1; i >= 0; i--) {
    ans.at(i) = min(ans.at(i + 1), di.d.at(i) + di2.d.at(i));
  }

  ll tmp = 1e15;
  for (int i = 0; i < n; i++) {
    cout << tmp - ans.at(i) << endl;
  }

  return 0;
}

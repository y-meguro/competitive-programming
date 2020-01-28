#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
const ll INF = 1e15;

struct Edge {
  int to;
  ll dist;
};

ll N;
vector<vector<Edge>> G; // 行き用
vector<vector<Edge>> G2; // 帰り用

struct Dijkstra {
  vector<ll> d;

  Dijkstra(int s, vector<vector<Edge>> &g) {
    d.resize(N, INF);
    d.at(0) = 0;

    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0, s));

    while (!q.empty()) {
      P p = q.top();
      q.pop();
      int v = p.second;
      if (d.at(v) < p.first) continue;

      for (Edge e : g.at(v)) {
        if (d.at(e.to) > d.at(v) + e.dist) {
          d.at(e.to) = d.at(v) + e.dist;
          q.push(P(d.at(e.to), e.to));
        }
      }
    }
  }

  ll time(int x) {
    return d.at(x);
  }
};

int main() {
  ll M, T;
  cin >> N >> M >> T;

  G.resize(N);
  G2.resize(N);

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;

    G.at(a).push_back(Edge{b, c});
    G2.at(b).push_back(Edge{a, c});
  }

  Dijkstra di(0, G);
  Dijkstra di2(0, G2);

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (di.time(i) == INF || di2.time(i) == INF) continue;
    if (T >= di.time(i) - di2.time(i)) {
      ans = max(ans, (T - di.time(i) - di2.time(i)) * A.at(i));
    }
  }

  cout << ans << endl;

  return 0;
}

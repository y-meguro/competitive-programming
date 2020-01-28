#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int INF = 1e9;

struct Edge {
  int to;
  int cost;
};

vector<vector<Edge>> G;

struct Dijkstra {
  vector<int> d;

  Dijkstra(int s) {
    d.resize(G.size(), INF);
    d.at(s) = 0;

    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0, s));

    while (!q.empty()) {
      P p = q.top();
      q.pop();
      int v = p.second;
      if (d.at(v) < p.first) continue;

      for (Edge e : G.at(v)) {
        if (d.at(e.to) > d.at(v) + e.cost) {
          d.at(e.to) = d.at(v) + e.cost;
          q.push(make_pair(d.at(e.to), e.to));
        }
      }
    }
  }

  int fare(int x) {
    if (d.at(x) == INF) return -1;
    return d.at(x);
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  G.resize(n);

  for (int i = 0; i < k; i++) {
    int p;
    cin >> p;

    if (p == 0) {
      int a, b;
      cin >> a >> b;
      a--; b--;

      Dijkstra di(a);
      cout << di.fare(b) << endl;

    } else {
      int c, d, e;
      cin >> c >> d >> e;
      c--; d--;

      G.at(c).push_back(Edge{d, e});
      G.at(d).push_back(Edge{c, e});
    }
  }

  return 0;
}

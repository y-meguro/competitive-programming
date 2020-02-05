#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 1e13 + 1;

struct Edge {
  int from, to, cost;
  Edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
};

int N, M;
vector<Edge> es;
vector<ll> c;

void bellmanFord(int s) {
  c.at(s) = 0;
  rep(i, N) {
    rep(j, M) {
      Edge e = es.at(j);
      if (c.at(e.from) != INF && c.at(e.to) > c.at(e.from) + e.cost) {
        c.at(e.to) = c.at(e.from) + e.cost;
      }
    }
  }
}

int main() {
  cin >> N >> M;
  c.resize(N, INF);

  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;

    es.emplace_back(a, b, -c);
  }

  bellmanFord(0);
  ll ans = -c.at(N - 1);
  bellmanFord(0);

  if (-c.at(N - 1) != ans) {
    cout << "inf" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
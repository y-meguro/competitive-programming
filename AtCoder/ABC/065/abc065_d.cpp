#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
const ll INF = 1e15;

struct Edge {
  int to;
  ll cost;
};

int N;
vector<vector<Edge>> G;

ll prim() {
  vector<ll> mincost(N, INF);
  vector<bool> reached(N, false);

  mincost.at(0) = 0;

  priority_queue<P, vector<P>, greater<P> > q;
  q.push(P(0, 0));

  ll ans = 0;

  while (!q.empty()) {
    P p = q.top();
    q.pop();

    int v = p.second;

    if (reached.at(v)) continue;
    reached.at(v) = true;
    ans += mincost.at(v);

    for (Edge e : G.at(v)) {
      if (mincost.at(e.to) > e.cost) {
        mincost.at(e.to) = e.cost;
        q.push(P(mincost.at(e.to), e.to));
      }
    }
  }
  return ans;
}

int main() {
  cin >> N;
  G.resize(N);

  vector<P> forX(N);
  vector<P> forY(N);
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;

    forX.at(i) = (P(x, i));
    forY.at(i) = (P(y, i));
  }

  sort(forX.begin(), forX.end());
  sort(forY.begin(), forY.end());

  ll before = forX.at(0).first;
  int beforeI = forX.at(0).second;

  for (int i = 1; i < N; i++) {
    ll x = forX.at(i).first;
    int currentI = forX.at(i).second;
    G.at(currentI).push_back(Edge{beforeI, x - before});
    G.at(beforeI).push_back(Edge{currentI, x - before});

    before = x;
    beforeI = currentI;
  }

  before = forY.at(0).first;
  beforeI = forY.at(0).second;
  for (int i = 1; i < N; i++) {
    ll y = forY.at(i).first;
    int currentI = forY.at(i).second;
    G.at(currentI).push_back(Edge{beforeI, y - before});
    G.at(beforeI).push_back(Edge{currentI, y - before});

    before = y;
    beforeI = currentI;
  }

  cout << prim() << endl;

  return 0;
}

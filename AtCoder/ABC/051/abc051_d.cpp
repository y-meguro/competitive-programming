#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

int N, tot;
vector<vector<Edge>> G;
vector<vector<bool>> used;

struct Dijkstra {
  vector<int> d;
  vector<int> prev;

  Dijkstra(int s) {
    d.resize(N, INF);
    prev.resize(N, INF);
    used.resize(N, vector<bool>(N, false));

    d.at(s) = 0;

    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0, s)); // firstが始点からの距離、secondが頂点
    while (!q.empty()) {
      int cost = q.top().first;
      int v = q.top().second;
      q.pop();
      if (d.at(v) < cost) continue;

      for (Edge e : G.at(v)) {
        if (d.at(e.to) > d.at(v) + e.cost) {
          d.at(e.to) = d.at(v) + e.cost;
          q.push(make_pair(d.at(e.to), e.to));
          prev.at(e.to) = v;
        }
      }
    }
  }

  void checkPrev(int s) {
    rep(i, N) {
      if (prev.at(i) == INF || i == s) continue;
      if (!used.at(i).at(prev.at(i))) {
        tot++;
        used.at(i).at(prev.at(i)) = true;
        used.at(prev.at(i)).at(i) = true;
      }
    }
  }
};

int main() {
  int M;
  cin >> N >> M;
  G.resize(N);

  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;

    G.at(a).emplace_back(b, c);
    G.at(b).emplace_back(a, c);
  }

  rep(i, N) {
    Dijkstra di(i);
    di.checkPrev(i);
  }
  cout << M - tot << endl;
  return 0;
}
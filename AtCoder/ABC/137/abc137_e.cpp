#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 1e12;

struct Edge {
  int from, to, cost;
  Edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
};

int N, M;
vector<Edge> es;
vector<ll> p;

void bellmanFord(int s) {
  p.at(s) = 0;
  rep(i, N * 2) {
    rep(j, M) {
      Edge e = es.at(j);
      if (p.at(e.from) != INF && p.at(e.to) > p.at(e.from) + e.cost) {
        if (i < N - 1) {
          p.at(e.to) = p.at(e.from) + e.cost;
        } else {
          p.at(e.to) = -INF; // ループしているところには -INF をいれる
        }
      }
    }
  }
}

int main() {
  int P;
  cin >> N >> M >> P;
  p.resize(N, INF);

  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--; B--;
    C = -(C - P);

    es.emplace_back(A, B, C);
  }

  bellmanFord(0);

  if (p.at(N - 1) == -INF) {
    cout << "-1" << endl;
  } else {
    cout << max(0ll, -p.at(N - 1)) << endl;
  }
  return 0;
}
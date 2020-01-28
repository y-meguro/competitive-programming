#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> parent;
  vector<int> height;

  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      parent.push_back(i);
      height.push_back(0);
    }
  }

  int find (int x) {
    if (parent.at(x) == x) {
      return x;
    } else {
      parent.at(x) = find(parent.at(x));
      return parent.at(x);
    }
  }

  void unite(int x, int y) {
    int p = find(x);
    int q = find(y);
    if (p == q) return;

    if (height.at(p) < height.at(q)) {
      parent.at(p) = q;
    } else {
      parent.at(q) = p;
      if (height.at(p) == height.at(q)) height.at(p)++;
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    p.at(i) = a - 1;
  }

  UnionFind u(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;

    u.unite(x - 1, y - 1);
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (u.find(i) == u.find(p.at(i))) cnt++;
  }

  cout << cnt << endl;

  return 0;
}

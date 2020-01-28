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

  int find(int x) {
    if (parent.at(x) == x) {
      return x;
    } else {
      parent.at(x) = find(parent.at(x));
      return parent.at(x);
    }
  }

  void unite (int x, int y) {
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
  int N, K, L;
  cin >> N >> K >> L;

  UnionFind u1(N);
  for (int i = 0; i < K; i++) {
    int p, q;
    cin >> p >> q;

    u1.unite(p - 1, q - 1);
  }

  UnionFind u2(N);
  for (int i = 0; i < L; i++) {
    int r, s;
    cin >> r >> s;

    u2.unite(r - 1, s - 1);
  }

  map<pair<int, int>, int> m;

  for (int i = 0; i < N; i++) {
    m[make_pair(u1.find(i), u2.find(i))]++;
  }

  for (int i = 0; i < N; i++) {
    cout << m[make_pair(u1.find(i), u2.find(i))];

    if (i == N - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
  vector<int> parent;
  vector<int> height;

  // n要素で初期化
  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      parent.push_back(i);
      height.push_back(0);
    }
  }

  // 木の根を求める
  int find(int x) {
    if (parent.at(x) == x) {
      return x;
    } else {
      parent.at(x) = find(parent.at(x));
      return parent.at(x);
    }
  }

  // xとyの属する集合を併合
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

  // xとyが同じ集合に属するか否か
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  UnionFind u(N);

  rep(i, M) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    X--; Y--;
    u.unite(X, Y);
  }

  set<int> parents;
  rep(i, N) {
    int p = u.find(i);
    parents.insert(p);
  }
  cout << parents.size() << endl;
  return 0;
}
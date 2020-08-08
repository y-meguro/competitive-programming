#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
  vector<int> parent;
  vector<int> siz; // 素集合のサイズを表す

  // n要素で初期化
  UnionFind(int n) {
    siz.resize(n, 1);
    for (int i = 0; i < n; i++) {
      parent.push_back(i);
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
  void unite(int x, int y) {
    int p = find(x);
    int q = find(y);
    if (p == q) return;

    if (siz.at(p) < siz.at(q)) swap(p, q);
    siz.at(p) += siz.at(q);
    parent.at(q) = p;
  }

  // xとyが同じ集合に属するか否か
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // 素集合のサイズ
  int size(int x) {
    return siz.at(find(x));
  }
};

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<vector<int>> fr(N), br(N);
  UnionFind u(N);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    u.unite(A, B);
    fr.at(A).push_back(B);
    fr.at(B).push_back(A);
  }

  rep(i, K) {
    int C, D;
    cin >> C >> D;
    C--; D--;
    br.at(C).push_back(D);
    br.at(D).push_back(C);
  }

  rep(i, N) {
    int ans = u.size(i) - fr.at(i).size() - 1;
    for (int x : br.at(i)) {
      if (u.same(i, x)) ans--;
    }
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
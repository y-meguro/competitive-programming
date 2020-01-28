#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> p;
  vector<int> h;
  vector<int> num;

  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      p.push_back(i);
      h.push_back(0);
      num.push_back(1);
    }
  }

  int find(int x) {
    if (p.at(x) == x) {
      return x;
    }
    p.at(x) = find(p.at(x));
    return p.at(x);
  }

  void unite(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b) return;

    if (h.at(a) < h.at(b)) {
      p.at(a) = b;
      num.at(b) += num.at(a);
    } else {
      p.at(b) = a;
      num.at(a) += num.at(b);
      num.at(b) = 0;
      if (h.at(a) == h.at(b)) h.at(a)++;
    }
  }

  int size(int x) {
    return num.at(x);
  }
};

int main() {
  int N;
  cin >> N;
  UnionFind u(N);

  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    u.unite(i, A - 1);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (u.size(i) % 2 != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << N / 2 << endl;
  return 0;
}

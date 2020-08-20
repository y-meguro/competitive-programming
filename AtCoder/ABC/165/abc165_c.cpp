#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M, Q;
vector<int> a, b, c, d;

int score(vector<int> &A) {
  int ans = 0;
  rep(i, Q) {
    if (A.at(b.at(i)) - A.at(a.at(i)) == c.at(i)) ans += d.at(i);
  }
  return ans;
}

int dfs(vector<int> &A) {
  // Aが完成していたら得点をチェック
  if ((int)A.size() == N) return score(A);

  // 数列を作成
  int res = 0;
  int prev = (A.empty() ? 1 : A.back());
  for (int i = prev; i <= M; i++) {
    A.push_back(i);
    res = max(res, dfs(A));
    A.pop_back();
  }
  return res;
}

int main() {
  cin >> N >> M >> Q;
  a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
  rep(i, Q) {
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    a.at(i)--; b.at(i)--;
  }

  vector<int> A;
  cout << dfs(A) << endl;
  return 0;
}
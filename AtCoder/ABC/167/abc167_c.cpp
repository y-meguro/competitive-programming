#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> C(N);
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) {
    cin >> C.at(i);
    rep(j, M) {
      cin >> A.at(i).at(j);
    }
  }

  // 全パターン試す
  int ans = INT_MAX;
  for (int bits = 1; bits < (1 << N); bits++) {
    int cost = 0;
    vector<int> v(M, 0);
    for (int i = 0; i < N; i++) {
      if ((bits >> i) & 1) {
        // Ciが含まれる場合
        cost += C.at(i);
        rep(j, M) {
          v.at(j) += A.at(i).at(j);
        }
      }
    }

    bool res = true;
    rep(i, M) {
      if (v.at(i) < X) {
        res = false;
        break;
      }
    }
    if (res && cost < ans) {
      ans = cost;
    }
  }

  if (ans == INT_MAX) {
    ans = -1;
  }

  cout << ans << endl;
  return 0;
}
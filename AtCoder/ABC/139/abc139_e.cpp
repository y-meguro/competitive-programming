#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAXN = 1001;
const int MAXV = MAXN * (MAXN - 1) / 2;

vector<vector<int>> id(MAXN, vector<int>(MAXN));
int toId(int i, int j) {
  if (i > j) swap(i, j);
  return id.at(i).at(j);
}

vector<vector<int>> to(MAXV);
vector<int> dp(MAXV);
vector<bool> reached(MAXV);
vector<bool> calculated(MAXV);
int dfs(int v) {
  if (reached.at(v)) {
    if (!calculated.at(v)) return -1;
    return dp.at(v);
  }
  reached.at(v) = true;
  dp.at(v) = 1;
  for (int u : to.at(v)) {
    int res = dfs(u);
    if (res == -1) return -1;
    dp.at(v) = max(dp.at(v), res + 1);
  }
  calculated.at(v) = true;
  return dp.at(v);
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N - 1));
  rep(i, N) {
    rep(j, N - 1) {
      cin >> A.at(i).at(j);
      A.at(i).at(j)--;
    }
  }

  int V = 0;
  rep(i, N) {
    rep(j, N) {
      if (i < j) {
        id.at(i).at(j) = V++;
      }
    }
  }

  rep(i, N) {
    rep(j, N - 1) {
      A.at(i).at(j) = toId(i, A.at(i).at(j));
    }
    rep(j, N - 2) {
      to.at(A.at(i).at(j + 1)).push_back(A.at(i).at(j)); // 逆向きに辺をはる
    }
  }

  int ans = 0;
  rep(i, V) {
    int res = dfs(i);
    if (res == -1){
      cout << -1 << endl;
      return 0;
    } else {
      ans = max(ans, res);
    }
  }
  cout << ans << endl;
  return 0;
}
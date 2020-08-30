#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> f(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    f.at(a).push_back(b);
    f.at(b).push_back(a);
  }

  vector<bool> checked(n, false);
  // 全部の点からはじまるグループの人数を求める
  deque<int> q;
  int ans = 0;
  rep(i, n) {
    if (checked.at(i)) continue;
    q.push_back(i);
    checked.at(i) = true;
    int tmp = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop_front();
      for (auto u : f.at(x)) {
        if (checked.at(u)) continue;
        q.push_back(u);
        checked.at(u) = true;
        tmp++;
      }
    }
    ans = max(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
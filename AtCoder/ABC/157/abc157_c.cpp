#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  if (M == 0) {
    if (N == 1) {
      cout << 0 << endl;
    } else {
      cout << pow(10, N - 1) << endl;
    }
    return 0;
  }
  map<int, int> m;
  bool check = false;
  rep(i, M) {
    int s, c;
    cin >> s >> c;
    if (m.count(s)) {
      if (m.at(s) != c) {
        cout << -1 << endl;
        return 0;
      }
    } else if (N != 1 && s == 1) {
      if (c == 0) {
        cout << -1 << endl;
        return 0;
      } else {
        check = true;
        m[s] = c;
      }
    } else if (N == 1) {
      check = true;
      m[s] = c;
    } else {
      m[s] = c;
    }
  }
  if (!check) {
    m[1] = 1;
  }
  int ans = 0;
  for (auto x : m) {
    ans += pow(10, N - x.first) * x.second;
  }
  cout << ans << endl;
  return 0;
}
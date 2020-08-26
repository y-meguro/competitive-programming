#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;

  // 働ける最大日数をカウントする
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s.at(i) == 'o') {
      cnt++;
      i += c;
    }
  }
  if (cnt > k) {
    cout << "" << endl;
    return 0;
  }

  // 必ず働く日を求める
  vector<bool> w(n, false);
  for (int i = n - 1; i >= 0; i--) {
    if (s.at(i) == 'o') {
      w.at(i) = true;
      i -= c;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s.at(i) == 'o') {
      if (w.at(i)) {
        cout << i + 1 << endl;
      }
      i += c;
    }
  }
  return 0;
}

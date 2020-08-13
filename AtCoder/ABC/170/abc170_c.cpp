#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int X, N;
  cin >> X >> N;
  vector<bool> ans(210, true);

  rep(i, N) {
    int p;
    cin >> p;
    if (p - X >= 0) {
      int a = (p - X) * 2;
      ans.at(a) = false;
    } else {
      int b = (X - p) * 2 - 1;
      ans.at(b) = false;
    }
  }

  rep(i, 210) {
    if (ans.at(i)) {
      if (i % 2 == 0) {
        cout << X + i / 2 << endl;
      } else {
        cout << X - (i + 1) / 2 << endl;
      }
      break;
    }
  }
  return 0;
}
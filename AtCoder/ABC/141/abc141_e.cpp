#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int l = 0;
  int r = 1e4;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    map<string, int> m;
    bool ok = false;
    rep(i, N) {
      string x = S.substr(i, mid);
      if (m.count(x)) {
        if (m.at(x) + mid <= i) {
          ok = true;
          break;
        }
      } else {
        m[x] = i;
      }
    }
    if (ok) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
  return 0;
}
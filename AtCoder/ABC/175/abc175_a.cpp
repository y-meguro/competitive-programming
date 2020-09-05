#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int ans = 0, tmp = 0;
  rep(i, 3) {
    if (s.at(i) == 'R') ++tmp;
    else tmp = 0;
    ans = max(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  string c;
  cin >> N >> c;

  int numR = 0;
  rep(i, N) {
    if (c.at(i) == 'R') numR++;
  }

  int ans = 0;
  rep(i, numR) {
    if (c.at(i) == 'W') ans++;
  }

  cout << ans << endl;
  return 0;
}
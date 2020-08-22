#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);
  rep(i, N) cin >> A.at(i);

  int now = 0;
  ll ans = 0;
  rep(i, N) {
    if (A.at(i) < now) {
      ans += now - A.at(i);
    } else {
      now = A.at(i);
    }
  }

  cout << ans << endl;
  return 0;
}
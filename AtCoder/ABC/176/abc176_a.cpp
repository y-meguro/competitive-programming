#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, X, T;
  cin >> N >> X >> T;
  int ans = (((N - 1) / X) + 1) * T;
  cout << ans << endl;
  return 0;
}
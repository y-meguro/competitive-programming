#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll mod = 1e9 + 7;

int main() {
  string S;
  cin >> S;
  int n = S.size();

  vector<vector<ll>> dp(n + 1, vector<ll>(13, 0));
  dp.at(0).at(0) = 1;

  rep(i, n) {
    char c = S.at(i);
    if (c == '?') {
      rep(j, 13) {
        rep(k, 10) {
          dp.at(i + 1).at((j * 10 + k) % 13) += dp.at(i).at(j);
          dp.at(i + 1).at((j * 10 + k) % 13) %= mod;
        }
      }
    } else {
      int x = c - '0';
      rep(j, 13) {
        dp.at(i + 1).at((j * 10 + x) % 13) += dp.at(i).at(j);
        dp.at(i + 1).at((j * 10 + x) % 13) %= mod;
      }
    }
  }
  cout << dp.at(n).at(5) << endl;
  return 0;
}
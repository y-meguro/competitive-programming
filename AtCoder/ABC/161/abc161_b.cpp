#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n, 0);
  int sum = 0;
  rep(i, n) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  sort(a.begin(), a.end());

  string ans = (a.at(n - m) * 4 * m >= sum) ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}
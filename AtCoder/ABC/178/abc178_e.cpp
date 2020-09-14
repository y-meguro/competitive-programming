#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a, b;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    a.push_back(x + y);
    b.push_back(x - y);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = max(a.at(n - 1) - a.at(0), b.at(n - 1) - b.at(0));
  cout << ans << endl;
  return 0;
}
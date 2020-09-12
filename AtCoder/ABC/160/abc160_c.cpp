#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  int longest = a.at(0) + (k - a.at(n - 1));
  rep(i, n - 1) {
    int x = a.at(i + 1) - a.at(i);
    longest = max(longest, x);
  }

  cout << k - longest << endl;
  return 0;
}
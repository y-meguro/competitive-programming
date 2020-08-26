#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  vector<int> path;
  vector<int> order(n + 1, -1);
  int v = 1;
  while (order.at(v) == -1) {
    order.at(v) = path.size();
    path.push_back(v);
    v = a.at(v - 1);
  }

  int period = path.size() - order.at(v);
  int before = order.at(v);
  if (k < before) {
    cout << path.at(k) << endl;
  } else {
    k -= before;
    k %= period;
    cout << path.at(before + k) << endl;
  }

  return 0;
}
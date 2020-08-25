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

  int next = 1;
  while (order.at(next) == -1) {
    order.at(next) = path.size();
    path.push_back(next);
    next = a.at(next - 1);
  }
  int cycle = path.size() - order.at(next);
  int before = order.at(next);

  if (k < before) {
    cout << path.at(k) << endl;
  } else {
    k -= before;
    k %= cycle;
    cout << path.at(before + k) << endl;
  }
  return 0;
}
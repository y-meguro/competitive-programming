#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> pos(N + 1);
  rep(i, N) {
    int p;
    cin >> p;
    pos.at(p) = i + 1;
  }

  multiset<int> ms;
  rep(i, 2) {
    ms.insert(0);
    ms.insert(N + 1);
  }
  ll ans = 0;
  for (int i = N; i >= 1; i--) {
    // インデックスの順は l1 < l2 < pos.at(i) < r1 < r2 となるようにする
    ms.insert(pos.at(i));
    auto itr = ms.find(pos.at(i));
    rep(j, 2) itr--;
    ll l1 = *itr;
    itr++;
    ll l2 = *itr;
    rep(j, 2) itr++;
    ll r1 = *itr;
    itr++;
    ll r2 = *itr;

    ans += ((l2 - l1) * (r1 - pos.at(i)) + (pos.at(i) - l2) * (r2 - r1)) * i;
  }
  cout << ans << endl;
  return 0;
}
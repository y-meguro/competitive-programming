#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);

  int l = 0, r = 1e9;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    auto f = [&](int x) {
      ll now = 0;
      rep(i, N) {
        now += (A.at(i) - 1) / x;
      }
      return now <= K;
    };
    if (f(mid)) r = mid;
    else l = mid;
  }
  cout << r << endl;
  return 0;
}
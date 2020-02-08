#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  rep(i, N) cin >> A.at(i);

  ll tot = 0; // 合計水量
  ll x = 0; // 奇数番目を2倍したもの
  rep(i, N) {
    tot += A.at(i);
    if (i % 2 == 0) {
      x += A.at(i) * 2;
    }
  }

  vector<ll> B(N);
  B.at(0) = x - tot;
  rep(i, N - 1) {
    B.at(i + 1) = (A.at(i) - B.at(i) / 2) * 2;
  }

  rep(i, N) {
    if (i != N - 1) {
      cout << B.at(i) << " ";
    } else {
      cout << B.at(i) << endl;
    }
  }
  return 0;
}
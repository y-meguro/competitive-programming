#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, D, A;
  cin >> N >> D >> A;

  vector<P> m(N);
  rep(i, N) {
    int X, H;
    cin >> X >> H;
    m.at(i) = P(X, (H + A - 1) / A);
  }
  sort(m.begin(), m.end());

  queue<P> q; // 関係する爆発を入れる
  ll acc = 0; // そこまでの爆発により、次のモンスターに対して減らせる体力量
  ll ans = 0;
  rep(i, N) {
    int x = m.at(i).first;
    int num = m.at(i).second;
    while (!q.empty() && q.front().first < x) {
      acc -= q.front().second;
      q.pop();
    }

    num -= acc;

    if (num > 0) {
      ans += num;
      acc += num;
      q.push(P(x + 2 * D, num));
    }
  }
  cout << ans << endl;
  return 0;
}
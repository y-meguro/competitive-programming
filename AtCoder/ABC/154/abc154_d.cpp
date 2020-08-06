#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  rep(i, N) cin >> p.at(i);

  double tmp = 0.0;
  rep(i, K) {
    tmp += p.at(i);
  }
  double x = tmp;
  for (int i = K; i < N; i++) {
    tmp += p.at(i);
    tmp -= p.at(i - K);
    x = max(x, tmp);
  }

  cout << fixed << setprecision(12) << (x + K) / 2 << endl;

  return 0;
}

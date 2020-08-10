#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<ll> A(N + 1, 0);
  vector<ll> B(M + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
    A.at(i) += A.at(i - 1);
  }
  for (int i = 1; i <= M; i++) {
    cin >> B.at(i);
    B.at(i) += B.at(i - 1);
  }

  int j = M;
  int ans = 0;
  rep(i, N + 1) {
    if (A.at(i) > K) break;
    while (A.at(i) + B.at(j) > K && j > 0) j--;
    ans = max(ans, i + j);
  }
  cout << ans << endl;
  return 0;
}
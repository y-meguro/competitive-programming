#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);

  vector<int> GCD1(N);
  vector<int> GCD2(N);
  GCD1.at(0) = A.at(0);
  GCD2.at(N - 1) = A.at(N - 1);

  for (int i = 1; i < N; i++) {
    GCD1.at(i) = __gcd(GCD1.at(i - 1), A.at(i));
  }

  for (int i = N - 2; i >= 0; i--) {
    GCD2.at(i) = __gcd(GCD2.at(i + 1), A.at(i));
  }

  int ans = max(GCD1.at(N - 2), GCD2.at(1));
  for (int i = 1; i <= N - 2; i++) {
    int x = __gcd(GCD1.at(i - 1), GCD2.at(i + 1));
    ans = max(ans, x);
  }
  cout << ans << endl;
  return 0;
}
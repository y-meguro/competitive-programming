#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> A(N + 1);
  for (int i = 0; i <= N; i++) {
    cin >> A.at(i);
  }

  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += min(A.at(i), B.at(i));
    B.at(i) -= min(A.at(i), B.at(i));
    ans += min(A.at(i + 1), B.at(i));
    A.at(i + 1) -= min(A.at(i + 1), B.at(i));
  }

  cout << ans << endl;

  return 0;
}

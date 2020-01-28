#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.at(i) = a - i - 1;
  }
  sort(A.begin(), A.end());

  ll b = A.at(N / 2);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += abs(A.at(i) - b);
  }

  cout << ans << endl;

  return 0;
}

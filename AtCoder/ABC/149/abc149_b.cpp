#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll A, B, K;
  cin >> A >> B >> K;

  if (A < K) {
    K -= A;
    A = 0;
    if (B < K) {
      B = 0;
    } else {
      B -= K;
    }
  } else {
    A -= K;
  }

  cout << A << " " << B << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  int x = sqrt(N);

  for (int i = x; i >= 1; i--) {
    if (N % i == 0) {
      cout << N / i + i - 2 << endl;
      break;
    }
  }

  return 0;
}

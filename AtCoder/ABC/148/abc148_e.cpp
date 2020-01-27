#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  if (N % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  long long a = 10;
  long long ans = 0;
  while (N / a != 0) {
    ans += N / a;
    a *= 5;
  }

  cout << ans << endl;

  return 0;
}

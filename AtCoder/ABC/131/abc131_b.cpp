#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;

  int ans = (L + (L + N - 1)) * N / 2;
  if (L > 0) {
    ans -= L;
  } else if (L + N - 1 < 0) {
    ans -= L + N - 1;
  }

  cout << ans << endl;

  return 0;
}

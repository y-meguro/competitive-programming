#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int ans = (N - 1) / (K - 1);
  if ((N - 1) % (K - 1) != 0) ans++;

  cout << ans << endl;

  return 0;
}

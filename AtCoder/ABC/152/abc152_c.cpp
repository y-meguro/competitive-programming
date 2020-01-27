#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  int minNum = 1e6;
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;

    if (p < minNum) {
      minNum = p;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

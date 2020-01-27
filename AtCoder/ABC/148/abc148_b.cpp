#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;

  string ans = "";
  for (int i = 0; i < N; i++) {
    ans += S[i];
    ans += T[i];
  }

  cout << ans << endl;

  return 0;
}

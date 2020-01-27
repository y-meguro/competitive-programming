#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 1;
  char before = S[0];
  for (int i = 1; i < S.size(); i++) {
    if (S[i] != before) {
      ans++;
      before = S[i];
    }
  }

  cout << ans << endl;

  return 0;
}

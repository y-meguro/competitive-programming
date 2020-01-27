#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;

  string T;
  cin >> T;

  int ans = 0;
  for (int i = 0; i < T.size(); i++) {
    if (i < K) {
      if (T[i] == 's') ans += R;
      if (T[i] == 'p') ans += S;
      if (T[i] == 'r') ans += P;
    } else {
      if (T[i - K] == T[i]) {
        T[i] = 'a';
      } else {
        if (T[i] == 's') ans += R;
        if (T[i] == 'p') ans += S;
        if (T[i] == 'r') ans += P;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

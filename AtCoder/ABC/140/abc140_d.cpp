#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;

  int cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    if (S[i] != S[i + 1]) cnt++;
  }

  int x = (cnt + 1) / 2;
  if (x <= K) {
    cout << N - 1 << endl;
  } else {
    cout << N - cnt - 1 + 2 * K << endl;
  }

  return 0;
}

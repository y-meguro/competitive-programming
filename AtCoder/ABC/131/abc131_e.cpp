#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int num = (N - 1) * (N - 2) / 2;
  if (K > num) {
    cout << -1 << endl;
    return 0;
  }
  cout << N * (N - 1) / 2 - K << endl;

  // スターを作る
  for (int i = 1; i < N; i++) {
    cout << i << " " << N << endl;
  }

  if (num - K == 0) return 0;

  // K個になるよう調整
  int cnt = 0;
  for (int i = 1; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      cout << i << " " << j << endl;
      cnt++;
      if (cnt == num - K) return 0;
    }
  }

  return 0;
}

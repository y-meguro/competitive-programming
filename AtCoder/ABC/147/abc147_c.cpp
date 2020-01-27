#include <bits/stdc++.h>
using namespace std;

int counter(int bits) {
  if (bits == 0) {
    return 0;
  }
  return counter(bits >> 1) + (bits & 1);
}

int main() {
  int N;
  cin >> N;

  int A[16];
  int x[16][16];
  int y[16][16];

  for (int i = 1; i <= N; i++) {
    cin >> A[i];

    for (int j = 1; j <= A[i]; j++) {
      cin >> x[i][j] >> y[i][j];
    }
  }

  int result = 0;

  // bitsが1となっている人は正直者と仮定し、矛盾が起きないかチェックする
  for (int bits = 1; bits < (1 << N) ; bits++) {
    bool check = true;

    for (int i = 1; i <= N; i++) {
      // i番目の人が不親切の場合は、矛盾は起きない
      int honest = (bits >> (i - 1)) & 1;
      if (!honest) {
        continue;
      }
      // i番目の人が正直者の場合のみ、x[i][j]とy[i][j]を調べる
      for (int j = 1; j <= A[i]; j++) {
        int honest2 = (bits >> (x[i][j] - 1)) & 1; // x[i][j]で指定している人が正直者かどうか
        int testimony = y[i][j]; // i番目の人の証言、y[i][j]
        if (honest2 ^ testimony) {
          check = false;
        }
      }
    }
    if (check) {
      result = max(result, counter(bits));
    }
  }

  cout << result << endl;
  return 0;
}

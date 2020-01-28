#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int t[N];
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  int result = 1000;
  for (int bits = 0; bits < (1 << N); bits++) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < N; i++) {
      if (bits & (1 << i)) {
        a += t[i];
      } else {
        b += t[i];
      }
    }
    if (max(a, b) < result) {
      result = max(a, b);
    }
  }

  cout << result << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int x[N], y[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  int max = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      int d = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
      if (d > max) {
        max = d;
      }
    }
  }

  cout << sqrt(max) << endl;

  return 0;
}

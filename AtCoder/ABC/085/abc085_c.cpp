#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;

  int x = -1;
  int y = -1;
  int z = -1;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      int k = N - i - j;
      if (Y - 10000 * i - 5000 * j == 1000 * k && k >= 0) {
        x = i;
        y = j;
        z = k;
        break;
      }
    }
  }

  cout << x << " " << y << " " << z << " " << endl;
  return 0;
}

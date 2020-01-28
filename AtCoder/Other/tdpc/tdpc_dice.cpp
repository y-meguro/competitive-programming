#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, D;
  cin >> N >> D;

  int x = 0;
  int y = 0;
  int z = 0;
  while (D % 2 == 0) {
    x++;
    D /= 2;
  }
  while (D % 3 == 0) {
    y++;
    D /= 3;
  }
  while (D % 5 == 0) {
    z++;
    D /= 5;
  }
  if (D > 1) {
    cout << 0 << endl;
    return 0;
  }

  double memo[N+1][x+1][y+1][z+1] = {0};
  memo[0][0][0][0] = 1.0;

  for (int i = 0; i < N; i++) {
    for (int a = x; a >= 0; a--) {
      for (int b = y; b >= 0; b--) {
        for (int c = z; c >= 0; c--) {
          double tmp = memo[i][a][b][c] / 6.0;
          if (tmp > 0) {
            memo[i+1][a][b][c] += tmp; // 1
            memo[i+1][min(a+1, x)][b][c] += tmp; // 2
            memo[i+1][a][min(b+1, y)][c] += tmp; // 3
            memo[i+1][min(a+2, x)][b][c] += tmp; // 4
            memo[i+1][a][b][min(c+1, z)] += tmp; // 5
            memo[i+1][min(a+1, x)][min(b+1, y)][c] += tmp; // 6
          }
        }
      }
    }
  }

  cout << memo[N][x][y][z] << endl;

  return 0;
}

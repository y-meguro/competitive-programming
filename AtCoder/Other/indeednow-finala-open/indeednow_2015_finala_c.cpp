#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  long long dp[101][101][101] = {0};
  for (int i = 0; i < N; i++) {
    int a, b, c;
    long long w;
    cin >> a >> b >> c >> w;
    dp[a][b][c] = max(w, dp[a][b][c]);
  }

  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; k <= 100; k++) {
        if (i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
        if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
        if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    cout << dp[x][y][z] << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K, M;
  cin >> N >> K >> M;

  int tot = 0;
  rep(i, N-1) {
    int A;
    cin >> A;
    tot += A;
  }

  int x = M * N - tot;
  if (x <= K) {
    cout << max(x, 0) << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
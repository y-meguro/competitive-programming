#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  string S;
  cin >> N >> S;

  ll numR = 0;
  ll numG = 0;
  ll numB = 0;
  rep(i, N) {
    if (S[i] == 'R') numR++;
    else if (S[i] == 'G') numG++;
    else numB++;
  }
  ll ans = numR * numG * numB;

  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      if (2 * j - i >= N) continue;
      if (S[i] == S[j]) continue;
      if (S[i] != S[2 * j - i] && S[j] != S[2 * j - i]) ans--;
    }
  }

  cout << ans << endl;
  return 0;
}
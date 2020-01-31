#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> a(N);
  rep(i, N) cin >> a.at(i);

  vector<bool> dp(K + 1, false);
  for (int i = 1; i <= K; i++) {
    rep(j, N) {
      if (i - a.at(j) >= 0 && !dp.at(i - a.at(j))) {
        dp.at(i) = true;
      }
    }
  }

  if (dp.at(K)) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
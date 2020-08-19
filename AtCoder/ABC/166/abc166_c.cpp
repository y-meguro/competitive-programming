#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  rep(i, N) cin >> H.at(i);

  vector<bool> res(N, true);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    if (H.at(A) > H.at(B)) {
      res.at(B) = false;
    } else if (H.at(A) == H.at(B)) {
      res.at(A) = false;
      res.at(B) = false;
    } else {
      res.at(A) = false;
    }
  }

  int ans = 0;
  rep(i, N) {
    if (res.at(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> x(M);
  rep(i, N) {
    int A, B;
    cin >> A >> B;

    if (A > M) continue;
    x.at(M - A).push_back(B);
  }

  priority_queue<int> q;
  ll ans = 0;
  for (int i = M - 1; i >= 0; i--) {
    for (int b : x.at(i)) {
      q.push(b);
    }
    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
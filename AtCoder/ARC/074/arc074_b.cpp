#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> a(3 * N);
  priority_queue<int> q, q2;
  ll sum = 0;
  ll sum2 = 0;
  vector<ll> x(N + 1, 0), y(N + 1, 0);

  for (int i = 0; i < 3 * N; i++) {
    cin >> a.at(i);
  }

  for (int i = 0; i < 2 * N; i++) {
    q.push(-a.at(i)); // 負の値にして入れる
    sum += a.at(i);

    if (q.size() > N) {
      sum += q.top();
      q.pop();
    }

    if (q.size() == N) {
      x.at(i - (N - 1)) = sum;
    }
  }

  for (int i = 3 * N - 1; i >= N; i--) {
    q2.push(a.at(i));
    sum2 += a.at(i);

    if (q2.size() > N) {
      sum2 -= q2.top();
      q2.pop();
    }

    if (q2.size() == N) {
      y.at(i - N) = sum2;
    }
  }

  ll ans = -LLONG_MAX;
  for (int i = 0; i <= N; i++) {
    ll score = x.at(i) - y.at(i);
    if (score > ans) ans = score;
  }

  cout << ans << endl;

  return 0;
}

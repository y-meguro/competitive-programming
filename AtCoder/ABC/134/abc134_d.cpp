#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> a.at(i);
  }

  vector<int> b(N + 1);
  int cnt = 0;
  for (int i = N; i >= 1; i--) {
    int sum = 0;
    for (int j = 2; j <= N / i; j++) {
      sum += b.at(i * j);
    }
    if (a.at(i) % 2 == sum % 2) {
      b.at(i) = 0;
    } else {
      b.at(i) = 1;
      cnt++;
    }
  }

  cout << cnt << endl;
  if (cnt == 0) return 0;

  for (int i = 1; i <= N; i++) {
    if (b.at(i) == 1) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
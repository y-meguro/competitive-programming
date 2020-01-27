#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
  }

  sort(v.begin(), v.end());

  double ans = v.at(0);
  for (int i = 1; i < N; i++) {
    ans = (ans + v.at(i)) / 2;
  }
  cout << ans << endl;

  return 0;
}

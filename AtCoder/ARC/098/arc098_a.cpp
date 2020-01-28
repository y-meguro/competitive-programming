#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  vector<int> count(N, 0);
  for (int i = 1; i < N; i++) {
    if (S[i] == 'E') count.at(0)++;
  }

  for (int i = 1; i < N; i++) {
    count.at(i) = count.at(i - 1);
    if (S[i - 1] == 'W') count.at(i)++;
    if (S[i] == 'E') count.at(i)--;
  }

  int ans = 1e6;
  for (int i = 0; i < N; i++) {
    if (count.at(i) < ans) ans = count.at(i);
  }

  cout << ans << endl;

  return 0;
}

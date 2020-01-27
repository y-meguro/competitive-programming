#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N;

  map<string, int> m;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    if (m.count(s)) {
      m.at(s)++;
    } else {
      m[s] = 1;
    }
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;

    if (m.count(s)) {
      m.at(s)--;
    } else {
      m[s] = -1;
    }
  }

  int ans = 0;
  for (auto x : m) {
    if (x.second > ans) {
      ans = x.second;
    }
  }

  cout << ans << endl;

  return 0;
}

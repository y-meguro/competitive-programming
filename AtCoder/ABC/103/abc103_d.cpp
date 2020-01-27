#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> ab(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    ab.at(i) = make_pair(b, a);
  }
  sort(ab.begin(), ab.end());

  int ans = 0;
  int last = 0;
  for (int i = 0; i < M; i++) {
    int a = ab.at(i).second;
    int b = ab.at(i).first;

    if (a >= last) {
      ans++;
      last = b;
    }
  }

  cout << ans << endl;

  return 0;
}

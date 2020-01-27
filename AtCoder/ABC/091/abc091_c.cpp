#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> ab(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = make_pair(b, a);
  }

  vector<pair<int, int>> cd(N);
  for (int i = 0; i < N; i++) {
    int c, d;
    cin >> c >> d;
    cd.at(i) = make_pair(c, d);
  }

  sort(ab.rbegin(), ab.rend());
  sort(cd.begin(), cd.end());

  int ans = 0;
  // 青から見て、次の条件を満たす赤とペアにする
  // x座標が小さいかつ、y座標が最も大きい
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int c = cd.at(i).first;
      int d = cd.at(i).second;

      int a = ab.at(j).second;
      int b = ab.at(j).first;

      if (c > a && d > b) {
        ab.at(j).first = 2 * N;
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}

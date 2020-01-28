#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  bool xy[N][N] = { false };
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;

    xy[x-1][y-1] = true;
    xy[y-1][x-1] = true;
  }

  int result = 0;
  // 派閥を構成する議員のパターンを全パターン調べる
  for (int bits = 0; bits < (1 << N); bits++) {
    vector<int> vec;
    bool check = true;
    for (int i = 0; i < N; i++) {
      if (bits & (1 << i)) {
        for (int j = 0; j < vec.size(); j++) {
          if (xy[i][vec.at(j)]) {
            continue;
          } else {
            check = false;
            break;
          }
        }
        if (check) {
          vec.push_back(i);
        } else {
          break;
        }
      }
    }
    if (check && vec.size() > result) {
      result = vec.size();
    }
  }

  cout << result << endl;
  return 0;
}

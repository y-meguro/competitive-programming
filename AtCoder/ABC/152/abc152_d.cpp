#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> cnt(10, vector<int>(10, 0));

  for (int i = 1; i <= N; i++) {
    string x = to_string(i);
    int a = x[0] - '0'; // 先頭
    int b = i % 10; // 末尾

    if (a == 0 || b == 0) continue;
    cnt.at(a).at(b)++;
  }

  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      ans += cnt.at(i).at(j) * cnt.at(j).at(i);
    }
  }

  cout << ans << endl;

  return 0;
}

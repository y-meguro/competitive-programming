#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }

  for (int i = N - 1; i >= 1; i--) {
    if (H.at(i) >= H.at(i - 1)) continue;
    if (H.at(i) + 1 >= H.at(i - 1)) {
      H.at(i - 1)--;
      continue;
    }
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  int x = 1;
  for (int i = 0; i < N; i++) {
    if (a.at(i) == x) x++;
  }

  if (x == 1) {
    cout << -1 << endl;
  } else {
    cout << N - x + 1 << endl;
  }

  return 0;
}

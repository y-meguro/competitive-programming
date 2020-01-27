#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N;
  cin >> H >> N;

  int x = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;

    x += A;
  }

  if (x >= H) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

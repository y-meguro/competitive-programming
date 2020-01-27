#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  if (N % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 0; i < N / 2; i++) {
    if (S[i] != S[N / 2 + i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}

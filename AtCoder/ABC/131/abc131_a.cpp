#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  for (int i = 1; i < S.size(); i++) {
    if (S[i - 1] == S[i]) {
      cout << "Bad" << endl;
      return 0;
    }
  }

  cout << "Good" << endl;

  return 0;
}

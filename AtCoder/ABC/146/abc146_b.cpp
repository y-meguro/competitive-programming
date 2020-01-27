#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  for (int i = 0; i < S.size(); i++) {
    char c = (S[i] - 'A' + N) % 26 + 'A';
    cout << c;
  }
  cout << endl;

  return 0;
}

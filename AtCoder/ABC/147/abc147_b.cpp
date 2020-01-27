#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int count = 0;
  for (int i = 0; i < S.size() / 2; i++) {
    char front = S.at(i);
    char back = S.at(S.size() - 1 - i);

    if (front != back) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

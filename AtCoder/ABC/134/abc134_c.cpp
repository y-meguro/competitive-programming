#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int first = 0;
  int second = 0;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);

    if (A.at(i) > first) {
      second = first;
      first = A.at(i);
    } else if (A.at(i) > second) {
      second = A.at(i);
    }
  }

  for (int i = 0; i < N; i++) {
    if (A.at(i) == first) {
      cout << second << endl;
    } else {
      cout << first << endl;
    }
  }

  return 0;
}

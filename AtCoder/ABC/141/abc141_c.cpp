#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, Q;
  cin >> N >> K >> Q;

  vector<int> x(N + 1, 0);
  for (int i = 0; i < Q; i++) {
    int A;
    cin >> A;
    x.at(A)++;
  }

  for (int i = 1; i <= N; i++) {
    if (x.at(i) + K > Q) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}

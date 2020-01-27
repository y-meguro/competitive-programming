#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> x(N + 1);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    x.at(A) = i + 1;
  }

  for (int i = 1; i <= N; i++) {
    cout << x.at(i);
    if (i != N) cout << " ";
  }
  cout << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, N, M;
  cin >> T >> N;

  queue<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push(a);
  }

  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }

  for (int i = 0; i < M; i++) {
    int b = B.at(i);
    bool check = false;

    while (!A.empty()) {
      int a = A.front();
      A.pop();

      if (a < b - T) {
        continue;
      } else if (a <= b) {
        check = true;
        break;
      } else {
        break;
      }
    }
    if (!check) {
      cout << "no" << endl;
      return 0;
    }
  }

  cout << "yes" << endl;

  return 0;
}

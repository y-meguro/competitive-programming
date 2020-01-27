#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> P(N), Q(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> Q.at(i);
  }

  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++) {
    a.at(i) = i + 1;
    b.at(i) = i + 1;
  }

  int x = 0;
  int y = 0;

  do {
    bool check = true;
    x++;
    for (int i = 0; i < N; i++) {
      if (a.at(i) != P.at(i)) {
        check = false;
        break;
      }
    }
    if (check) {
      break;
    }
  } while (next_permutation(a.begin(), a.end()));

  do {
    bool check = true;
    y++;
    for (int i = 0; i < N; i++) {
      if (b.at(i) != Q.at(i)) {
        check = false;
        break;
      }
    }
    if (check) {
      break;
    }
  } while (next_permutation(b.begin(), b.end()));

  cout << abs(x - y) << endl;

  return 0;
}

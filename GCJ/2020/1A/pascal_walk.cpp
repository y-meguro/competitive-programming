#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t + 1 << ":" << endl;
    cout << "1 1" << endl;

    if (N == 1) continue;

    int r = 2;
    int k = 2;
    int sum = 2;
    int next = 0;
    while (sum <= N) {
      cout << r << " " << k << endl;
      next = r;
      r++;
      sum += next;
    }

    r--;
    sum -= next;
    for (int i = 0; i < (N - sum); i++) {
      cout << r + i << " " << 1 << endl;
    }
  }
  return 0;
}
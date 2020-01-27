#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;

  long long common = 1;
  long long a = 1;

  long long i = 2;
  while (A != 1) {
    if (A % i == 0 && B % i == 0) {
      common *= i;
      A /= i;
      B /= i;
      continue;
    } else if (A % i == 0 && B % i != 0) {
      a *= i;
      A /= i;
      continue;
    }
    i++;
  }

  long long ans = common * a * B;
  cout << ans << endl;

  return 0;
}

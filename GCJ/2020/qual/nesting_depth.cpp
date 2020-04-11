#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string S;
    cin >> S;
    int n = S.length();

    string S2 = "0" + S + "0";

    vector<int> p(n + 1, 0);
    for (int i = 0; i < n + 1; i++) {
      p.at(i) = S2.at(i + 1) - S2.at(i);
    }

    string ans = "";
    for (int i = 0; i < n + 1; i++) {
      int x = p.at(i);
      if (x > 0) {
        for (int j = 0; j < x; j++) {
          ans += "(";
        }
      } else if (x < 0) {
        x = -x;
        for (int j = 0; j < x; j++) {
          ans += ")";
        }
      }
      if (i != n) {
        ans += S.at(i);
      }
    }

    cout << "Case #" << t + 1 << ": " << ans << endl;
  }

  return 0;
}
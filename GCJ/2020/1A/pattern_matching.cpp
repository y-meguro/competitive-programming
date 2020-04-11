#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;

    vector<string> P(N);
    for (int i = 0; i < N; i++) {
      cin >> P.at(i);
    }

    string first = "";
    string second = "";
    string ans = "";
    for (int i = 0; i < N; i++) {
      string p = P.at(i);
      int pos = p.find("*");
      int pos2 = p.rfind("*");
      if (pos != pos2) continue;

      string p1 = p.substr(0, pos);
      string p2 = p.substr(pos + 1);
      if (p1.size() > first.size()) {
        int check1 = p1.find(first);
        if (check1 != 0) {
          ans = "*";
          break;
        } else {
          first = p1;
        }
      } else {
        int check2 = first.find(p1);
        if (check2 != 0) {
          ans = "*";
          break;
        }
      }

      if (p2.size() > second.size()) {
        int check3 = p2.rfind(second);
        if (check3 + (int)second.size() != (int)p2.size()) {
          ans = "*";
          break;
        } else {
          second = p2;
        }
      } else {
        int check4 = second.rfind(p2);
        if (check4 + (int)p2.size() != (int)second.size()) {
          ans = "*";
          break;
        }
      }

      if (ans != "*") {
        ans = first + second;
      }
    }
    cout << "Case #" << t + 1 << ": " << ans << endl;
  }
  return 0;
}
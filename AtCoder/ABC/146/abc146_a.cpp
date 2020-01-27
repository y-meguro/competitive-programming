#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  vector<string> days = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  for (int i = 0; i < 7; i++) {
    if (days.at(i) == S) {
      cout << 7 - i << endl;
    }
  }

  return 0;
}

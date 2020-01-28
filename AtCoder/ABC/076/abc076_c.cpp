#include <bits/stdc++.h>
using namespace std;

int main() {
  string str, T;
  cin >> str >> T;

  for (int i = str.size() - T.size(); i >= 0; i--) {
    string sub = str.substr(i, T.size());
    bool check = true;
    for (int j = 0; j < T.size(); j++) {
      if (sub.at(j) != '?' && sub.at(j) != T.at(j)) {
        check = false;
        break;
      }
    }

    if (check) {
      str = str.substr(0, i) + T + str.substr(i + T.size());
      for (int j = 0; j < str.size(); j++) {
        if (str.at(j) == '?') str.at(j) = 'a';
      }
      cout << str << endl;
      return 0;
    }
  }

  cout << "UNRESTORABLE" << endl;
  return 0;
}

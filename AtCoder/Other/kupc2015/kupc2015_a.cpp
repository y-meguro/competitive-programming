#include <bits/stdc++.h>
using namespace std;

string tokyo = "tokyo";
string kyoto = "kyoto";

int search(string str) {
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str.substr(i, 5) == tokyo || str.substr(i, 5) == kyoto) {
      ans++;
      i += 4;
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;

  string S[T];
  for (int i = 0; i < T; i++) {
    cin >> S[i];
  }

  for (int i = 0; i < T; i++) {
    int ans = search(S[i]);
    cout << ans << endl;
  }

  return 0;
}

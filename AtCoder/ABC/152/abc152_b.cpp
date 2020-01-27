#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  string x = "";
  string y = "";

  for (int i = 0; i < b; i++) {
    x += to_string(a);
  }
  for (int i = 0; i < a; i++) {
    y += to_string(b);
  }
  if (a < b) {
    cout << x << endl;
  } else {
    cout << y << endl;
  }
  return 0;
}

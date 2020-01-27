#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int a = N / 1000;
  int b = (N / 100) % 10;
  int c = (N / 10) % 10;
  int d = N % 10;

  if (b == c && (a == b || c == d)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
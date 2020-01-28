#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> m;
  map<int, int> m2;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;

    if (i % 2 == 0) {
      if (m.count(v)) {
        m.at(v)++;
      } else {
        m[v] = 1;
      }
    } else {
      if (m2.count(v)) {
        m2.at(v)++;
      } else {
        m2[v] = 1;
      }
    }
  }

  int first = 0;
  int firstCount = 0;
  int secondCount = 0;
  for (auto x : m) {
    if (x.second > firstCount) {
      secondCount = firstCount;
      first = x.first;
      firstCount = x.second;
    } else if (x.second > secondCount) {
      secondCount = x.second;
    }
  }

  int first2 = 0;
  int firstCount2 = 0;
  int secondCount2 = 0;
  for (auto x : m2) {
    if (x.second > firstCount2) {
      secondCount2 = firstCount2;
      first2 = x.first;
      firstCount2 = x.second;
    } else if (x.second > secondCount2) {
      secondCount2 = x.second;
    }
  }

  if (first != first2) {
    cout << n - firstCount - firstCount2 << endl;
  } else {
    if (firstCount + secondCount2 > secondCount + firstCount2) {
      cout << n - firstCount - secondCount2 << endl;
    } else {
      cout << n - secondCount - firstCount2 << endl;
    }
  }

  return 0;
}

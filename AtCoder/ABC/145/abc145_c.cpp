#include <bits/stdc++.h>
using namespace std;

int x[8], y[8];

double dist(int a, int b) {
  int dx = x[a] - x[b];
  int dy = y[a] - y[b];
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    v.at(i) = i;
  }
  double sum = 0.0;
  do {
    for (int i = 0; i < N - 1; i++) {
      sum += dist(v.at(i), v.at(i + 1));
    }
  } while (next_permutation(v.begin(), v.end()));

  int total = 1;
  for (int i = 2; i <= N; i++) {
    total *= i;
  }

  cout << fixed << setprecision(10) << sum / total << endl;

  return 0;
}

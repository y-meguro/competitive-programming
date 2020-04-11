#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    vector<vector<int>> M(N, vector<int>(N, 0));

    int k = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> M.at(i).at(j);
        if (i == j) {
          k += M.at(i).at(j);
        }
      }
    }

    int r = 0;
    for (int i = 0; i < N; i++) {
      vector<bool> v(101, false);
      for (int j = 0; j < N; j++) {
        int x = M.at(i).at(j);
        if (v.at(x)) {
          r++;
          break;
        } else {
          v.at(x) = true;
        }
      }
    }

    int c = 0;
    for (int j = 0; j < N; j++) {
      vector<bool> v(101, false);
      for (int i = 0; i < N; i++) {
        int x = M.at(i).at(j);
        if (v.at(x)) {
          c++;
          break;
        } else {
          v.at(x) = true;
        }
      }
    }

    cout << "Case #" << t + 1 << ": " << k << " " << r << " " << c << endl;
  }

  return 0;
}
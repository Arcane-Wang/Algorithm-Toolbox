#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int m = a.size();
  int n = b.size();
  int p = c.size();
  int D[m + 1][n + 1][p + 1];

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= p; ++k) {
        if (i == 0 || j == 0 || k == 0) {
          D[i][j][k] = 0;
        } else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
          D[i][j][k] = D[i - 1][j - 1][k - 1] + 1;
        } else {
          D[i][j][k] = std::max(std::max(D[i - 1][j][k], D[i][j - 1][k]), D[i][j][k - 1]);
        }
      }
    }
  }

  return D[m][n][p];
}


int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}

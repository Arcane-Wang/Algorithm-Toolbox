#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int m = a.size();
  int n = b.size();
  int D[m + 1][n + 1];
  for (int i = 0; i <= m; ++i) {
    D[i][0] = 0;
  }
  for (int j = 0; j <= n; ++j) {
    D[0][j] = 0;
  }
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= m; ++i) {
      int insertion = D[i][j - 1];
      int deletion = D[i - 1][j];
      int match = D[i - 1][j - 1] + 1;
      int mismatch = D[i - 1][j - 1];
      if (a[i - 1] == b[j - 1]) {
        D[i][j] = std::max(std::max(insertion, deletion), match);
      } else {
        D[i][j] = std::max(std::max(insertion, deletion), mismatch);
      }
    }
  }
  return D[m][n];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}

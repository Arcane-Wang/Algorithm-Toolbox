#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.size();
  int n = str2.size();
  int D[m + 1][n + 1];
  for (int i = 0; i <= m; ++i) {
    D[i][0] = i;
  }
  for (int j = 0; j <= n; ++j) {
    D[0][j] = j;
  }
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= m; ++i) {
      int insertion = D[i][j - 1] + 1;
      int deletion = D[i - 1][j] + 1;
      int match = D[i - 1][j - 1];
      int mismatch = D[i - 1][j - 1] + 1;
      if (str1[i - 1] == str2[j - 1]) {
        D[i][j] = std::min(std::min(insertion, deletion), match);
      } else {
        D[i][j] = std::min(std::min(insertion, deletion), mismatch);
      }
    }
  }
  return D[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

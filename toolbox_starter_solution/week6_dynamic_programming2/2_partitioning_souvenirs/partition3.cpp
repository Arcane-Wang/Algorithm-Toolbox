#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  int sum = std::accumulate(A.begin(), A.end(), 0);
  if (sum % 3 != 0) {
    return 0;
  }
  int n = A.size();
  int W = sum / 3;
  vector<vector<int>> value(n+1, vector<int>(W+1, 0)); // value[i][j] is the maximum value of bars 1..i with capacity j
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      value[i][j] = value[i-1][j]; // don't take bar i
      if (A[i-1] <= j) { // take bar i
        int val = value[i-1][j-A[i-1]] + A[i-1]; // value of bar i + value of bars 1..i-1 with capacity j-w[i-1]
        if (value[i][j] < val) { // update value[i][j] if val is greater
          value[i][j] = val; 
        }
      }
    }
  }
  if (value[n][W] != W) {
    return 0;
  }
  // check if there are two other subsets with sum W
  vector<int> B = A; // copy A to B
  for (int i = 0; i < n; i++) { // remove bars in A that are in the first subset
    if (B[i] == 0) { // bar i is already removed
      continue;
    }
    for (int j = i+1; j < n; j++) { // remove bars in A that are in the second subset
      if (B[j] == 0) { // bar j is already removed
        continue;
      }
      if (B[i] + B[j] == W) { // found two bars that sum to W
        B[i] = 0;
        B[j] = 0;
        break;
      }
    }
  }
  if (std::accumulate(B.begin(), B.end(), 0) == W) {
    return 1;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}

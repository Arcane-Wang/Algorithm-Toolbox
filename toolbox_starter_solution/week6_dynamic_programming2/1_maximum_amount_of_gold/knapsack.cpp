#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size(); // number of bars
  vector<vector<int>> value(n+1, vector<int>(W+1, 0)); // value[i][j] is the maximum value of bars 1..i with capacity j
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      value[i][j] = value[i-1][j]; // don't take bar i
      if (w[i-1] <= j) { // take bar i
        int val = value[i-1][j-w[i-1]] + w[i-1]; // value of bar i + value of bars 1..i-1 with capacity j-w[i-1]
        if (value[i][j] < val) { // update value[i][j] if val is greater
          value[i][j] = val; 
        }
      }
    }
  }
  return value[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}

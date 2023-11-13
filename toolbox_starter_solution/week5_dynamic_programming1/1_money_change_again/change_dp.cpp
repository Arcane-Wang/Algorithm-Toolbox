#include <iostream>
#include <vector>

int get_change(int m) {
  //write your code here
  std::vector<int> coins = {1, 3, 4};
  std::vector<int> min_coins(m + 1, 0);
  for (int i = 1; i <= m; ++i) {
    min_coins[i] = 1000;
    for (int j = 0; j < coins.size(); ++j) {
      if (i >= coins[j]) {
        int num_coins = min_coins[i - coins[j]] + 1;
        if (num_coins < min_coins[i]) {
          min_coins[i] = num_coins;
        }
      }
    }
  }
  return min_coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

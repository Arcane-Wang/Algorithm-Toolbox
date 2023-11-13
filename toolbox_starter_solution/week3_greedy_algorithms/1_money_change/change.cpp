#include <iostream>
#include <vector>

int get_change(int m) {
  //write your code here
  int n = 0;
  std::vector<int> coins = {10, 5, 1};
  int idx = 0;
  while (m > 0){
    n += m / coins[idx];
    m %= coins[idx];
    idx++;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

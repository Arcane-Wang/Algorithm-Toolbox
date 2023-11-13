#include <iostream>

int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;
  }
  int a_prime = a % b;
  return gcd_fast(b, a_prime);
}

long long lcm_fast(int a, int b) {
  return (long long) a * b / gcd_fast(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

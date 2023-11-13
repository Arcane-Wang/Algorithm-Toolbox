#include <iostream>

int get_fibonacci_last_digit_fast(int n) {
    // write your code here
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i-1] + fib[i-2]) % 10;
    }
    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }

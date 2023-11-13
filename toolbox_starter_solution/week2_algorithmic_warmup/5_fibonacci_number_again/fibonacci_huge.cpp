#include <iostream>
#include <map>

long long get_fibonacci_huge_fast(long long n, long long m, std::map<long long, long long>& fib) {
    if (fib.find(n) != fib.end()) {
        return fib[n];
    }
    long long pre_previous = 0, previous = 1, current = 0;
    for (long long i = 2; i <= n; ++i) {
        current = (pre_previous + previous) % m;
        pre_previous = previous;
        previous = current;
        if (previous == 1 && current == 0) {
            long long period = i - 1;
            long long index = n % period;
            long long temp = get_fibonacci_huge_fast(index, m, fib);
            fib[n] = temp;
            return temp;
        }
    }
    fib[n] = current;
    return current;
}

int main() {
    long long n, m;
    std::map<long long, long long> fib;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m, fib) << '\n';
}

#include <iostream>
#include <vector>
#include <algorithm>


unsigned long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    unsigned long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        unsigned long long next = a + b;
        a = b;
        b = next;
    }
    return b;
}

unsigned long long factorial(int n) {
    unsigned long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

std::vector<int> get_divisors(int n) {
    std::vector<int> divs;
    if (n <= 0) return divs;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
    }
    std::sort(divs.begin(), divs.end());
    return divs;
}

int main() {
    int n;
    std::cout << "введите число: ";
    std::cin >> n;

    std::cout << "фиб: " << fibonacci(n) << "\n";
    std::cout << "!: " << factorial(n) << "\n";
    
    std::cout << "делители " << n << ": ";
    for (int d : get_divisors(n)) {
        std::cout << d << " ";
    }
    std::cout << "\n";
    return 0;
}

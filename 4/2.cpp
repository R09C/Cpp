#include <iostream>
#include <vector>

unsigned long long fib(int n) {
    if (n < 2) return n;
    unsigned long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        auto next = a + b;
        a = b;
        b = next;
    }
    return b;
}

unsigned long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

std::vector<int> get_divisors(int n) {
    std::vector<int> divs, large;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) large.push_back(n / i);
        }
    }
    divs.insert(divs.end(), large.rbegin(), large.rend());
    return divs;
}

int main() {
    int n;
    std::cout << "введите число: ";
    if (!(std::cin >> n) || n < 0) return 1;

    if (n <= 93) std::cout << "фиб: " << fib(n) << '\n';
    else std::cout << "фиб: число слишком большое\n";
    if (n <= 20) std::cout << "!: " << fact(n) << '\n';
    else std::cout << "!: число слишком большое\n";

    if (n == 0) {
        std::cout << "у нуля бесконечно много делителей\n";
    } else {
        std::cout << "делители " << n << ":";
        for (int d : get_divisors(n)) std::cout << ' ' << d;
        std::cout << '\n';
    }
    return 0;
}

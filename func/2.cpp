#include <iostream>
#include <vector>

unsigned long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void get_divisors(int n, int i, std::vector<int>& divs) {
    if (i > n) return;
    if (n % i == 0) {
        divs.push_back(i);
    }
    get_divisors(n, i + 1, divs);
}

int main() {
    int n;
    std::cout << "введите число: ";
    std::cin >> n;

    std::cout << "фиб: " << fibonacci(n) << "\n";
    std::cout << "!: " << factorial(n) << "\n";
    
    std::vector<int> divs;
    get_divisors(n, 1, divs);

    std::cout << "делители " << n << ": ";
    for (int d : divs) {
        std::cout << d << " ";
    }
    std::cout << "\n";
    return 0;
}

#include <iostream>

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year;
    std::cout << "Введите год: ";
    std::cin >> year;

    if (is_leap_year(year)) {
        std::cout << year << " — високосный год\n";
    } else {
        std::cout << year << " — невисокосный год\n";
    }
    return 0;
}

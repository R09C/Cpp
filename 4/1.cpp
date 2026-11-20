#include <iostream>

bool is_v_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year;
    std::cout << "введите год: ";
    if (!(std::cin >> year)) return 1;

    if (is_v_year(year)) {
        std::cout << year << " високосный год\n";
    } else {
        std::cout << year << " невисокосный год\n";
    }
    return 0;
}

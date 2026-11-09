#include <iostream>

// bool is_v_year(int year) {
//     return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
// }

int main() {
    int year;
    std::cout << "введите год: ";
    std::cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        std::cout << year << " высокосный год\n";
    } else {
        std::cout << year << "невысокосный год\n";
    }
    return 0;
}

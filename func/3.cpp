#include <iostream>
#include <functional>

double get_price(double price, int count) {
    return price * count;
}

double calc(double price, int count, std::function<double(double, int)> func) {
    return func(price, count);
}

int main() {
    double price;
    int count;

    std::cout << "введите цену и количество: ";
    std::cin >> price >> count;

    std::cout << "стоимость: " << calc(price, count, get_price) << "\n";
    return 0;
}

#include <iostream>
#include <functional>

double get_price(double price, int count) {
    return price * count;
}

double calc(double sum ,double price, int count, std::function<double(double, int)> func) {
    return sum + func(price, count);
}

int main() {
    double price;
    int count;
    double sum;
    std::cout << "введите цену и количество: ";
    while(std::cin >> price >> count){
    sum = calc(sum,price,count,get_price);
    std::cout << "стоимость: " << sum << "\n";}
    return 0;
}

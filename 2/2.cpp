#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  system("chcp 65001 > nul");

  int age, stock;
  double total;
  bool hasPromo, isBlocked, hasMarked;

  cout << "Возраст клиента: ";
  cin >> age;
  cout << "Сумма корзины (руб): ";
  cin >> total;
  cout << "Есть промокод? (1 - да, 0 - нет): ";
  cin >> hasPromo;
  cout << "Аккаунт заблокирован? (1 - да, 0 - нет): ";
  cin >> isBlocked;
  cout << "Есть маркированные товары с возрастным цензом? (1 - да, 0 - нет): ";
  cin >> hasMarked;
  cout << "Остаток товара на складе: ";
  cin >> stock;

  if (isBlocked) {
    cout << "Отказ: аккаунт заблокирован\n";
    return 0;
  }
  if (age < 18 && hasMarked) {
    cout << "Отказ: пользователю меньше 18 лет, а в заказе есть маркированные "
            "товары\n";
    return 0;
  }
  if (stock <= 0) {
    cout << "Отказ: нет позиций на складе\n";
    return 0;
  }

  double discount = 0;
  if (total >= 10000)
    discount = 0.15;
  else if (total >= 5000 && hasPromo)
    discount = 0.10;

  double finalSum = total * (1 - discount);
  cout << "Заказ оформлен\n";
  cout << "Скидка: " << discount * 100 << "%\n";
  cout << "Итого к оплате: " << finalSum << " руб\n";
  return 0;
}

#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

enum class Status : uint8_t {
  Created,
  Paid,
  Shipped,
  Delivered,
  Cancelled
};

struct Order {
  double total;
  uint64_t id;
  Status status;
};

bool can_change(Status from, Status to){
  switch (from){
    case Status::Created:
      return to == Status::Paid or to == Status::Cancelled;
    case Status::Paid:
      return to == Status::Shipped or to == Status::Cancelled;
    case Status::Shipped:
      return to == Status::Delivered;
    case Status::Delivered:
    case Status::Cancelled:
      return false;
  }
  return false;
}

bool set_status(Order& order, Status next){
  if (not can_change(order.status, next)) return false;
  order.status = next;
  return true;
}

int main(){
  system("chcp 65001 > nul");

  Order ord{1500.0, 1, Status::Created};
  cout << sizeof(Status) << " " << sizeof(Order) << '\n';

  cout << set_status(ord, Status::Shipped) << '\n';
  cout << set_status(ord, Status::Paid) << '\n';
  cout << set_status(ord, Status::Shipped) << '\n';
  cout << set_status(ord, Status::Cancelled) << '\n';
  cout << set_status(ord, Status::Delivered) << '\n';
  cout << set_status(ord, Status::Created) << '\n';

  return 0;
}

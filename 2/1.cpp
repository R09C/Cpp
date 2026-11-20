#include <iostream>
#include <limits>
#include <typeinfo>

using namespace std;
int main() {
  cout << "bool " << sizeof(bool) << '\n'
       << "char " << sizeof(char) << '\n'
       << "signed char " << sizeof(signed char) << '\n'
       << "unsigned char " << sizeof(unsigned char) << '\n'
       << "wchar_t " << sizeof(wchar_t) << '\n'
       << "char8_t " << sizeof(char8_t) << '\n'
       << "char16_t " << sizeof(char16_t) << '\n'
       << "char32_t " << sizeof(char32_t) << '\n'
       << "short " << sizeof(short) << '\n'
       << "unsigned short " << sizeof(unsigned short) << '\n'
       << "int " << sizeof(int) << '\n'
       << "unsigned int " << sizeof(unsigned int) << '\n'
       << "long " << sizeof(long) << '\n'
       << "unsigned long " << sizeof(unsigned long) << '\n'
       << "long long " << sizeof(long long) << '\n'
       << "unsigned long long " << sizeof(unsigned long long) << '\n'
       << "float " << sizeof(float) << '\n'
       << "double " << sizeof(double) << '\n'
       << "long double " << sizeof(long double) << '\n'
       << "nullptr_t " << sizeof(decltype(nullptr)) << '\n';

  auto max_int = numeric_limits<unsigned int>::max();
  cout << "unsigned int: " << max_int << " + 1 = " << max_int + 1u << '\n';

  auto db = 2.1342145154277656;
  float b = static_cast<float>(db);
  cout.precision(17);
  cout << "double " << db << '\n' << "float " << b << '\n';

  auto a = 1;
  auto& ref = a;
  auto ptr = &a;
  ref++;
  cout << "auto: " << typeid(a).name() << ' ' << a << '\n';
  cout << "auto&: " << ref << '\n';
  cout << "auto pointer: " << typeid(ptr).name() << ' ' << *ptr << '\n';
  return 0;
}

#include <cmath>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>

using namespace std;

template <typename T>
class Vec {
  vector<T> values;

public:
  Vec(initializer_list<T> items) : values(items) {}
  explicit Vec(size_t n) : values(n) {}

  size_t size() const {
    return values.size();
  }

  decltype(auto) operator[](size_t i){
    return values[i];
  }

  decltype(auto) operator[](size_t i) const {
    return values[i];
  }
};

template <typename T>
auto norm(const Vec<T>& v){
  long double len = 0;
  for (size_t i = 0; i < v.size(); i++) {
    len = hypot(len, static_cast<long double>(v[i]));
  }
  return len;
}

template <typename T>
auto operator+(const Vec<T>& a, const Vec<T>& b){
  if (a.size() != b.size()) throw invalid_argument("разная длина векторов");
  Vec<T> res(a.size());
  for (size_t i = 0; i < a.size(); i++){
    res[i] = a[i] + b[i];
  }
  return res;
}

template <typename T, typename S>
  requires is_arithmetic_v<S>
auto operator*(const Vec<T>& v, S k){
  Vec<common_type_t<T, S>> res(v.size());
  for (size_t i = 0; i < v.size(); i++){
    res[i] = v[i] * k;
  }
  return res;
}

template <typename S, typename T>
  requires is_arithmetic_v<S>
auto operator*(S k, const Vec<T>& v){
  return v * k;
}

template <typename T>
auto operator*(const Vec<T>& a, const Vec<T>& b){
  if (a.size() != b.size()) throw invalid_argument("разная длина векторов");
  T sum = 0;
  for (size_t i = 0; i < a.size(); i++){
    sum += a[i] * b[i];
  }
  return sum;
}

template <typename T>
ostream& operator<<(ostream& os, const Vec<T>& v){
  for (size_t i = 0; i < v.size(); i++) {
    if (i != 0) os << ' ';
    os << v[i];
  }
  return os;
}

template <typename T>
bool operator==(const Vec<T>& a, const Vec<T>& b){
  if (a.size() != b.size()) return false;
  for (size_t i = 0; i < a.size(); i++){
    if (a[i] != b[i]) return false;
  }
  return true;
}

template <typename T>
bool operator!=(const Vec<T>& a, const Vec<T>& b){
  return not (a == b);
}

template <typename T>
bool operator<(const Vec<T>& a, const Vec<T>& b){
  return norm(a) < norm(b);
}

template <typename T>
bool operator>(const Vec<T>& a, const Vec<T>& b){
  return b < a;
}

int main(){
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif

  Vec<int> a = {3, 4, 0};
  Vec<int> b = {1, 2, 2};

  cout << a << '\n';
  cout << b << '\n';
  cout << (a + b) << '\n';
  cout << (a * 3) << '\n';
  cout << (2 * b) << '\n';
  cout << (a * b) << '\n';
  cout << norm(a) << " " << norm(b) << '\n';
  cout << (a == b) << " " << (a != b) << " "
       << (a > b) << " " << (a < b) << '\n';

  Vec<double> c = {1.5, -2.0, 2.5};
  Vec<double> d = {0.5, 4.0, -1.5};

  cout << (c + d) << '\n';
  cout << (c * 2.0) << '\n';
  cout << (c * d) << '\n';
  cout << norm(c) << " " << norm(d) << '\n';
  cout << (c < d) << '\n';

  return 0;
}

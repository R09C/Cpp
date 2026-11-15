#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
auto norm(const vector<T>& v){
  double sum = 0;
  for (auto x : v) sum += x * x;
  return sqrt(sum);
}

template <typename T>
auto operator+(const vector<T>& a, const vector<T>& b){
  vector<T> res(a.size());
  for (size_t i = 0; i < a.size(); i++){
    res[i] = a[i] + b[i];
  }
  return res;
}

template <typename T>
auto operator*(const vector<T>& v, T k){
  vector<T> res(v.size());
  for (size_t i = 0; i < v.size(); i++){
    res[i] = v[i] * k;
  }
  return res;
}

template <typename T>
auto operator*(T k, const vector<T>& v){
  return v * k;
}

template <typename T>
auto operator*(const vector<T>& a, const vector<T>& b){
  T sum = 0;
  for (size_t i = 0; i < a.size(); i++){
    sum += a[i] * b[i];
  }
  return sum;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  for (auto x : v) os << x << " ";
  return os;
}

namespace vec_cmp {

template <typename T>
bool operator==(const vector<T>& a, const vector<T>& b){
  if (a.size() != b.size()) return false;
  for (size_t i = 0; i < a.size(); i++){
    if (a[i] != b[i]) return false;
  }
  return true;
}

template <typename T>
bool operator!=(const vector<T>& a, const vector<T>& b){
  return not (a == b);
}

template <typename T>
bool operator<(const vector<T>& a, const vector<T>& b){
  return norm(a) < norm(b);
}

template <typename T>
bool operator>(const vector<T>& a, const vector<T>& b){
  return norm(a) > norm(b);
}

}

int main(){
  system("chcp 65001 > nul");

  vector<int> a = {3, 4, 0};
  vector<int> b = {1, 2, 2};

  cout << a << '\n';
  cout << b << '\n';
  cout << (a + b) << '\n';
  cout << (a * 3) << '\n';
  cout << (2 * b) << '\n';
  cout << (a * b) << '\n';
  cout << norm(a) << " " << norm(b) << '\n';
  cout << vec_cmp::operator==(a, b) << " "
       << vec_cmp::operator!=(a, b) << " "
       << vec_cmp::operator>(a, b) << " "
       << vec_cmp::operator<(a, b) << '\n';

  vector<double> c = {1.5, -2.0, 2.5};
  vector<double> d = {0.5, 4.0, -1.5};

  cout << (c + d) << '\n';
  cout << (c * 2.0) << '\n';
  cout << (c * d) << '\n';
  cout << norm(c) << " " << norm(d) << '\n';
  cout << vec_cmp::operator<(c, d) << '\n';

  return 0;
}

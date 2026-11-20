#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

class IntArray {
  size_t len;
  int* data;

public:
  explicit IntArray(size_t n) : len(n), data(n ? new int[n]{} : nullptr) {}

  ~IntArray(){
    delete[] data;
  }

  IntArray(const IntArray& other)
      : len(other.len), data(other.len ? new int[other.len] : nullptr){
    if (len != 0) copy_n(other.data, len, data);
  }

  IntArray& operator=(const IntArray& other){
    if (this == &other) return *this;
    int* tmp = other.len ? new int[other.len] : nullptr;
    if (other.len != 0) copy_n(other.data, other.len, tmp);
    delete[] data;
    len = other.len;
    data = tmp;
    return *this;
  }

  IntArray(IntArray&& other) noexcept : len(other.len), data(other.data){
    other.len = 0;
    other.data = nullptr;
  }

  IntArray& operator=(IntArray&& other) noexcept {
    if (this != &other){
      delete[] data;
      len = other.len;
      data = other.data;
      other.len = 0;
      other.data = nullptr;
    }
    return *this;
  }

  int& operator[](size_t i){
    return data[i];
  }

  const int& operator[](size_t i) const {
    return data[i];
  }

  size_t size() const {
    return len;
  }
};

int main(){
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif

  IntArray a(5);
  for (size_t i = 0; i < a.size(); i++) a[i] = i + 1;

  IntArray b = a;
  b[0] = 100;

  for (size_t i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << '\n';
  for (size_t i = 0; i < b.size(); i++) cout << b[i] << " ";
  cout << '\n';

  IntArray c(2);
  c = b;
  c = c;

  IntArray d = move(c);
  cout << c.size() << " " << d.size() << '\n';
  c = move(d);
  cout << d.size() << " " << c.size() << '\n';
  const IntArray& arr = c;
  for (size_t i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << '\n';

  return 0;
}

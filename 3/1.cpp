#include <array>
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iostream>

using namespace std;

const size_t N = 10000;
using Matrix = array<array<int, N>, N>;
Matrix matrix;

long long sum_rows(const Matrix& a) {
  long long sum = 0;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      sum += a[i][j];
    }
  }
  return sum;
}

long long sum_columns(const Matrix& a) {
  long long sum = 0;
  for (size_t j = 0; j < N; j++) {
    for (size_t i = 0; i < N; i++) {
      sum += a[i][j];
    }
  }
  return sum;
}

int main() {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      matrix[i][j] = static_cast<int>(i + j);
    }
  }
  auto t1 = chrono::steady_clock::now();
  auto sum1 = sum_rows(matrix);
  auto t2 = chrono::steady_clock::now();
  cout << sum1 << " строки: " << chrono::duration<double>(t2 - t1).count()
       << " c\n";
  t1 = chrono::steady_clock::now();
  auto sum2 = sum_columns(matrix);
  t2 = chrono::steady_clock::now();
  cout << sum2 << " столбцы: " << chrono::duration<double>(t2 - t1).count()
       << " c\n";
}

#include <array>
#include <chrono>
#include <cstddef>
#include <iostream>

using namespace std;

const size_t N = 10000;
array<array<int, N>, N> matrix;

int main() {
  system("chcp 65001 > nul");

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      matrix[i][j] = i + j;
    }
  }
  long long sum1 = 0;
  auto t1 = chrono::steady_clock::now();
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      sum1 += matrix[i][j];
    }
  }
  auto t2 = chrono::steady_clock::now();
  cout << sum1 << " строки: " << chrono::duration<double>(t2 - t1).count()
       << " c\n";
  long long sum2 = 0;
  t1 = chrono::steady_clock::now();

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      sum2 += matrix[j][i];
    }
  }
  t2 = chrono::steady_clock::now();
  cout << sum2 << " столбцы: " << chrono::duration<double>(t2 - t1).count()
       << " c\n";
}

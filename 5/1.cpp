


#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstddef>






auto partiton(std::vector<int>& mass, int left, int right, int pivout) {
  int i = left;
  int j = right;
  while (i <= j) {
    while (i <= j and mass[j] > pivout) j--;
    if (i <= j and mass[i] > pivout) {
      std::swap(mass[i], mass[j]);
      j--;
    }
    i++;
  }
  return j;
}

void quick_sort(std::vector<int>& mass, int left, int right) {
  if (left >= right) return;
  std::swap(mass[left + (right - left) / 2], mass[right]);
  int j = partiton(mass, left, right - 1, mass[right]);
  std::swap(mass[j + 1], mass[right]);
  quick_sort(mass, left, j);
  quick_sort(mass, j + 2, right);
}

void quick_sort(std::vector<int>& mass) {
  if (!mass.empty()) {
    quick_sort(mass, 0, static_cast<int>(mass.size()) - 1);
  }
}






int main(){
  std::vector<int> vec = {7, -2, 0, 5, -8, 3, 5, 1};
  auto last = std::remove_if(vec.begin(), vec.end(), [](int x){ return x < 0; });
  vec.erase(last, vec.end());
  quick_sort(vec);
  for (std::size_t i = 0; i < vec.size(); i++) {
    if (i != 0) std::cout << ' ';
    std::cout << vec[i];
  }
  std::cout << '\n';
}


#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;
int main() {
  system("chcp 65001 > nul");
  float v1, v2;
  cin >> v1 >> v2;
  float eps = 0.0001;

  if (eps < abs(v1 - v2)) {
    if (v1 > v2)
      cout << "v1 больше";
    else
      cout << "v2 больше";
  } else
    cout << "они равны";

  return 0;
}
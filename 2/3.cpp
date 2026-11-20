
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;
int main() {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif
  double v1, v2;
  if (!(cin >> v1 >> v2)) return 1;
  const double eps = 1e-9;

  if (eps < abs(v1 - v2)) {
    if (v1 > v2)
      cout << "v1 больше\n";
    else
      cout << "v2 больше\n";
  } else
    cout << "они равны\n";

  return 0;
}

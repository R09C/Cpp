


#include <vector>
#include <iostream>


int main(){
  int raw[100];
  std::vector<int> vec(raw,raw+100);
  for (int x : vec) std::cout << x << " ";
}
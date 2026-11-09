


#include <vector>
#include <iostream>
#include <algorithm>


int main(){
  int raw[100];
  std::vector<int> vec(raw,raw+100);
  for (int x : vec) std::cout << x << " ";
  std::cout << std::endl << std::endl;
  
  for(auto i = vec.begin();i!=vec.end();){
    if (*i<0){i = vec.erase(i);}
    else{
      ++i;
    }
  };
  std::sort(vec.begin(),vec.end());
  for (int x : vec) std::cout << x << " ";
}
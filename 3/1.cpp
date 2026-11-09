


#include <vector>
#include <iostream>


int main(){
  int raw[100];
  std::vector<int> vec(raw,raw+100);
  for (int x : vec) std::cout << x << " ";
  
  for(auto i = vec.begin();i!=vec.end();){
    if (*i<0){i = vec.erase(i);}
    else{
      ++i;
    }
  };
  for (int x : vec) std::cout << x << " ";
}
#include <iostream>
#include <typeinfo>

using namespace std;
int main() {
    cout.precision(16);
    int a = 1;
    float b = 2.1342145154277656;
    double  db = 2.1342145154277656;
    bool c ;
    char d;

    cout<<sizeof(a)<<'\n'<<sizeof(b)<<'\n'<<sizeof(c)<<'\n'<<sizeof(d);
    int i=0;
    while (i<30){a*=2;cout << a << '\n'; i++;};

    cout << db << '\n' <<b << '\n';

    auto a_u = 1;
    auto b_b = 2.1342145154277656;
    auto b_t = "a";
    cout << db << '\n' <<typeid(a_u).name()<< '\n';
    return 0;
   
}

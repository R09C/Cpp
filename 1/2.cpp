
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std::chrono;

using namespace std;
int main() {
  system("chcp 65001 > nul");
  string name;
  int day, month, year, age;
  char dot;
  cout << "привет, напиши свое имя и дату(дд.мм.гггг)";
  cin >> name;
  cin >> day >> dot >> month >> dot >> year;
  auto today = year_month_day{floor<days>(system_clock::now())};
  int cur_year = int(today.year());
  int cur_month = unsigned(today.month());
  int cur_day = unsigned(today.day());

  age = cur_year - year;
  if (month > cur_month || (month == cur_month && day > cur_day))
    age--;
  cout << "тебе вот столько лет" << age;
  return 0;
}
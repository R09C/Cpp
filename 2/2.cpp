
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>


using namespace std::chrono;

using namespace std;
int main() {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif
  string name;
  int d, m, y;
  char dot1, dot2;
  cout << "напиши свое имя: ";
  if (!getline(cin, name) || name.empty()) return 1;
  cout << "напиши дату рождения (дд.мм.гггг): ";
  if (!(cin >> d >> dot1 >> m >> dot2 >> y) || dot1 != '.' || dot2 != '.' ||
      d < 1 || d > 31 || m < 1 || m > 12 || y < 1 || y > 9999) {
    cout << "неверная дата\n";
    return 1;
  }
  auto birth = year{y} / m / d;
  auto now = time(nullptr);
  const auto* local = localtime(&now);
  if (local == nullptr) return 1;
  int cur_year = local->tm_year + 1900;
  int cur_month = local->tm_mon + 1;
  int cur_day = local->tm_mday;
  auto today = year{cur_year} / cur_month / cur_day;
  if (!birth.ok() || birth > today) {
    cout << "неверная дата\n";
    return 1;
  }

  int age = cur_year - y;
  if (m > cur_month || (m == cur_month && d > cur_day))
    age--;
  cout << "привет, " << name << '\n';
  cout << "тебе вот столько лет: " << age << '\n';
  return 0;
}

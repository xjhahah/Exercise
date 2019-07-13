#include <iostream>
#include <string>

using std::string;

int main() {
  int n = 0;

  while (std::cin >> n) {
    std::cin.get();
    string s;
    for (int i = 0; i < n; ++i) {
      getline(std::cin, s);
      if (i != n - 1) {
        if (s.find(',') == string::npos || s.find(' ') == string::npos) {
          std::cout << s << ',' << ' ';
        } else {
          std::cout << '\"' << s << '\"' << ',' << ' ';
        }
      } else {
        if (s.find(',') != -1 || s.find(' ') != -1)
          std::cout << '\"' << s << '\"' << std::endl;
        else
          std::cout << s << std::endl;
      }
      s.clear();
    }
  }
  return 0;
}

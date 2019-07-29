#include <iostream>
#include <string>

using std::string;

int main() {
  string s, t;
  while (std::cin >> s >> t) {
    string tmp = "";
    size_t i = 0;
    for (auto& e : t) {
      if (e == s[i] && i < s.size()) {
        tmp += e;
        i++;
      }
    }
    if (tmp.size() != s.size()) {
      std::cout << "No" << std::endl;
    } else {
      std::cout << "Yes" << std::endl;
    }
  }
  return 0;
}

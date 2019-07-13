#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string src, dst;
  while (getline(cin, src)) {
    getline(cin, dst);
    bool flag = false;
    auto it = src.begin();

    while (it != src.end()) {
      string tmp;
      if (*it == '"') {
        it++;
        while (it < src.end() && *it != '"') {
          tmp += *it;
        }
        if (tmp == dst) {
          flag = true;
          break;
        }
      } else if (*it != ',') {
        while (it < src.end() && *it != ',') {
          tmp += *it;
          it++;
        }
        if (tmp == dst) {
          flag = true;
          break;
        }
      }
      it++;
    }
    if (flag) {
      cout << "Ignore" << endl;
    } else {
      cout << "Important!" << endl;
    }
  }
  return 0;
}

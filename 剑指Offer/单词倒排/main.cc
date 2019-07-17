//单词倒排
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
  string s;
  while (getline(std::cin, s)) {
    vector<string> res;
    string tmp = "";
    for (const auto& e : s) {
      if (e >= 'a' && e <= 'z' || e >= 'A' && e <= 'Z') {
        tmp += e;
      } else {
        if (tmp.size() > 0) {
          res.push_back(tmp);
          tmp.clear();
        }
      }
    }
    if (tmp.size() > 0) {
      res.push_back(tmp);
    }

    for (int i = res.size() - 1; i > 0; i--) {
      std::cout << res[i] << ' ';
    }
    std::cout << res[0] << std::endl;
  }
  return 0;
}

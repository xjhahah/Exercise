#include <iostream>
#include <string>

using std::string;

int main() {
  int n = 0;
  while (std::cin >> n) {
    while (n--) {
      string s;
      std::cin.get();
      getline(std::cin, s);
      string s1 = "", s2 = "";
      size_t pos = s.find(' ');
      s1 += s.substr(0, pos);
      s2 += s.substr(pos + 1);
      int p1 = 0, p2 = 0;
      int num1 = 0, num2 = 0;
      bool flag = false;
      while (p1 < s1.size() || p2 < s2.size()) {
        while (p1 < s1.size() && s1[p1] != '.') {  //解析两个小数点之间的数字
          num1 = num1 * 10 + s1[p1] - '0';
          p1++;
        }
        while (p2 < s2.size() && s2[p2] != '.') {
          num2 = num2 * 10 + s2[p2] - '0';
          p2++;
        }
        if (num1 < num2) {
          flag = true;
        }
        if (num1 > num2) {
          flag = false;
          break;
        }
        num1 = 0;  //注意这里要置0
        num2 = 0;
        p1++;
        p2++;
      }
      if (flag) {
        std::cout << "true" << std::endl;
      } else {
        std::cout << "flase" << std::endl;
      }
    }
  }
  return 0;
}

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

    for(int i=0; i < src.length(); ++i) {
      string tmp;
      if (src[i] == '"') {
        i++;
        while (i < src.length() && src[i] != '"') {
          tmp += src[i];
          i++;
        }
        if (tmp == dst) {
          flag = true;
          break;
        }
      } else if (src[i] != ',') {
        while (i < src.length() && src[i] != ',') {
          tmp += src[i];
          i++;
        }
        if (tmp == dst) {
          flag = true;
          break;
        }
      }
    }
    if (flag) {
      cout << "Ignore" << endl;
    } else {
      cout << "Important!" << endl;
    }
  }
  return 0;
}

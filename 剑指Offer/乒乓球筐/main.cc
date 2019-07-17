//乒乓球筐
#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

int main() {
  string src, dst;
  while (std::cin >> src >> dst) {
    map<char, int> mp_src, mp_dst;
    bool flag = true;
    for (const auto& e : src) {
      mp_src[e]++;
    }
    for (const auto& e : dst) {
      mp_dst[e]++;
    }
    auto it = mp_dst.begin();
    while (it != mp_dst.end()) {
      if (mp_src[it->first] < it->second ) {
        flag = false;
        break;
      }
      it++;
    }
    if (flag) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}

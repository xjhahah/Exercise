//电话号码
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  string tmp = "22233344455566677778889999";
  int n = 0;
  while (cin >> n) {
    string s;
    set<string> res;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      int cnt = 0;
      string ss;
      for (auto& e : s) {
        if (e >= 'A' && e <= 'Z') {
          ss += tmp[e - 'A'];
          cnt++;
          if (cnt == 3) {
            ss += '-';
          }
        } else if (e >= '0' && e <= '9') {
          ss += e;
          cnt++;
          if (cnt == 3) {
            ss += '-';
          }
        }
      }
      res.emplace(ss);
    }
    for (const auto& phone : res) {
      cout << phone << endl;
    }
    cout << endl;
  }
  return 0;
}
/*
int main() {
  int n = 0;
  unordered_map<char, char> dic;
  dic.emplace('A', '2');
  dic.emplace('B', '2');
  dic.emplace('C', '2');
  dic.emplace('D', '3');
  dic.emplace('E', '3');
  dic.emplace('F', '3');
  dic.emplace('G', '4');
  dic.emplace('H', '4');
  dic.emplace('I', '4');
  dic.emplace('J', '5');
  dic.emplace('K', '5');
  dic.emplace('L', '5');
  dic.emplace('M', '6');
  dic.emplace('N', '6');
  dic.emplace('O', '6');
  dic.emplace('P', '7');
  dic.emplace('Q', '7');
  dic.emplace('R', '7');
  dic.emplace('S', '7');
  dic.emplace('T', '8');
  dic.emplace('U', '8');
  dic.emplace('V', '8');
  dic.emplace('W', '9');
  dic.emplace('X', '9');
  dic.emplace('Y', '9');
  dic.emplace('Z', '9');

  while (std::cin >> n) {
    string s;
    set<string> res;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      string ret = "";
      for (const auto& e : s) {
        if (isdigit(e)) {
          ret += e;
        } else if (isupper(e)) {
          ret += dic[e];
        }
      }
      if (ret.size() != 7) {
        continue;
      }
      ret = ret.substr(0, 3) + "-" + ret.substr(3);
      res.emplace(ret);
    }
    for (const auto& e : res) {
      std::cout << e << std::endl;
    }
    cout << endl;
  }
  return 0;
}
*/

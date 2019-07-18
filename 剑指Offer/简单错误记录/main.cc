//简单错误记录
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using std::map;
using std::vector;
using std::string;

string modifyName(string s) {
  int pos = s.find(' ');
  if (pos > 16) {
    s = s.substr(pos - 16);
  }
  return s;
}
int main() {
  string s;
  string line;
  vector<string> vs;
  vector<int> cnt;
  string tmp = "";
  int pos = 0;
  while (std::cin>>s>>line) {
    //1.找到最后一个\ 
	pos=s.find_last_of('\\');
    if (pos < 0) {
      break;
    }
    tmp = s.substr(pos + 1);
    tmp += ' ' + line;
    if (vs.empty() || std::find(vs.begin(), vs.end(), tmp) == vs.end()) {
      vs.push_back(tmp);
      cnt.push_back(1);
    } else {
      cnt[std::find(vs.begin(), vs.end(), tmp) - vs.begin()]++;
    }
  }
  size_t i = cnt.size() > 8 ? cnt.size() - 8 : 0;
  for (; i < cnt.size(); ++i) {
    std::cout << modifyName(vs[i]) << " " << cnt[i] << std::endl;
  }
  return 0;
}

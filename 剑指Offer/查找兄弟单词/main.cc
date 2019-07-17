//查找兄度单词
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isBrother(string str, string s) {
  if (str.size() == s.size()) {
    if (str == s)
		return false;
    sort(str.begin(), str.end());
    sort(s.begin(), s.end());
    if (str == s) 
		return true;
  }
  return false;
}
int main() {
  int num;
  while (cin >> num) {
    string str;
    string word, s;
    int index;
    vector<string> vs;
    for (int i = 0; i < num; ++i) {
      cin >> str;
      vs.push_back(str);
    }
    sort(vs.begin(), vs.end());  // 因为是字典，一定要排序！！
    cin >> word;
    cin >> index;
    int counts = 0;

    for (int i = 0; i < num; ++i) {
      if (isBrother(word, vs[i])) {
        counts++;
        if (counts == index) s = vs[i];
      }
    }
    if (!vs.empty()) cout << counts << endl;
    if (counts >= index) cout << s << endl;
  }
  return 0;
}

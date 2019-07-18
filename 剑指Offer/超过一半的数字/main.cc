#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

#define N 5

class Solution {
 public:
  int MoreThanHalfNum_Solution(vector<int> v) {
    map<int, int> mp;
    for (auto& e : v) {
      mp[e]++;
    }
    int len = v.size() / 2;
    for (auto& e : mp) {
      if (e.second > len) {
        return e.first;
      }
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> v(5, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> v[i];
  }
  std::cout << s.MoreThanHalfNum_Solution(v) << std::endl;
  return 0;
}

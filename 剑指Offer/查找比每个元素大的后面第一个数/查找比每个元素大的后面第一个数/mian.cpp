/*n个整数的无序数组，找到每个元素后面比它大的第一个数，要求时间复杂度为O(N)*/

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

vector<int> findMax(vector<int> num) {
  if (num.size() == 0) return num;
  vector<int> res(num.size());
  int i = 0;
  stack<int> s;
  while (i < num.size()) {
    if (s.empty() || num[s.top()] >= num[i]) {
      s.push(i++);
    } else {
      res[s.top()] = num[i];
      s.pop();
    }
  }
  while (!s.empty()) {
    res[s.top()] = INT_MAX;
    s.pop();
  }
  for (int i = 0; i < res.size(); i++) std::cout << res[i] << std::endl;
  return res;
}
int main() {
  vector<int> v = {2,1,5,3,7,5,9,0};
  auto ret = findMax(v);
  return 0;
}
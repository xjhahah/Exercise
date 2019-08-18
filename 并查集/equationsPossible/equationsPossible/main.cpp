#include "mian.h"

/*
解题思路：
1. 将所有"=="两端的字符合并到一个集合中
2. 检测"!=" 两端的字符是否在同一个结合中，如果在不满足，如果不在满足
*/
class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    UnionFindSet ufs(26);
    for (size_t i = 0; i < equations.size(); ++i) {
      // 将等号两端的字符合并到一个集合中
      if ('=' == equations[i][1]) {
        ufs.Union(equations[i][0] - 'a', equations[i][3] - 'a');
      }
    }
    for (size_t i = 0; i < equations.size(); ++i) {
      // 将等号两端的字符合并到一个集合中
      if ('!' == equations[i][1]) {
        // 如果"!="两端的字符在同一个集合中，不满足
        if (ufs.FindRoot(equations[i][0] - 'a') ==
            ufs.FindRoot(equations[i][3] - 'a'))
          return false;
      }
    }
    return true;
  }
};
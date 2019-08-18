#include "common.h"

// OJ-朋友圈
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    // 矩阵的行和列下标相当于人的编号，元素相当于两人是否为朋友关系
    UnionFindSet ufs(M.size());
    for (size_t i = 0; i < M.size(); ++i) {
      for (size_t j = 0; j < M[i].size(); ++j) {
        // 自己和自己的关系除外
        if (i == j) continue;
        // 如果i和j是朋友，将其添加到一个朋友圈
        if (1 == M[i][j]) ufs.Union(i, j);
      }
    }
    return ufs.Count();
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  std::cout << s.findCircleNum(v) << std::endl;
  return 0;
}
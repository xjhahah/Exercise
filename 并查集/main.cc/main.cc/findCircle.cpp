#include "common.h"

// OJ-����Ȧ
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    // ������к����±��൱���˵ı�ţ�Ԫ���൱�������Ƿ�Ϊ���ѹ�ϵ
    UnionFindSet ufs(M.size());
    for (size_t i = 0; i < M.size(); ++i) {
      for (size_t j = 0; j < M[i].size(); ++j) {
        // �Լ����Լ��Ĺ�ϵ����
        if (i == j) continue;
        // ���i��j�����ѣ�������ӵ�һ������Ȧ
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
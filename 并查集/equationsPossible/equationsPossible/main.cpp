#include "mian.h"

/*
����˼·��
1. ������"=="���˵��ַ��ϲ���һ��������
2. ���"!=" ���˵��ַ��Ƿ���ͬһ������У�����ڲ����㣬�����������
*/
class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    UnionFindSet ufs(26);
    for (size_t i = 0; i < equations.size(); ++i) {
      // ���Ⱥ����˵��ַ��ϲ���һ��������
      if ('=' == equations[i][1]) {
        ufs.Union(equations[i][0] - 'a', equations[i][3] - 'a');
      }
    }
    for (size_t i = 0; i < equations.size(); ++i) {
      // ���Ⱥ����˵��ַ��ϲ���һ��������
      if ('!' == equations[i][1]) {
        // ���"!="���˵��ַ���ͬһ�������У�������
        if (ufs.FindRoot(equations[i][0] - 'a') ==
            ufs.FindRoot(equations[i][3] - 'a'))
          return false;
      }
    }
    return true;
  }
};
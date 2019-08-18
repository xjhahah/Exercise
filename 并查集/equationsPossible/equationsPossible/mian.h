#pragma once
#pragma once

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

//���鼯
class UnionFindSet {
 public:
  //��ʼ��Ԫ��Ϊ-1
  UnionFindSet(size_t size) : _ufs(size, -1) {}

  //��һ��Ԫ�ؽ��б�ţ��ҵ���Ԫ�����ڼ��ϵ�����
  int FindRoot(int index) {
    //��������д洢�������Ǹ������ҵ�������һֱ����
    while (_ufs[index] >= 0) {
      index = _ufs[index];
    }
    return index;
  }

  bool Union(int x, int y) {
    int root1 = FindRoot(x);
    int root2 = FindRoot(y);

    // x,y�Ѿ���һ������
    if (root1 == root2) return false;
    // ������������Ԫ�غϲ�
    _ufs[root1] += _ufs[root2];
    // ������һ���������Ƹı������һ��
    _ufs[root2] = root1;
    return true;
  }
  // �����и����ĸ�������Ϊ���ϵĸ���
  size_t Count() const {
    size_t count = 0;
    for (auto e : _ufs) {
      if (e < 0) ++count;
    }
    return count;
  }

 private:
  vector<int> _ufs;
};

#pragma once

#include <iostream>
#include <vector>

using std::vector;

//并查集
class UnionFindSet {
 public:
  //初始化元素为-1
  UnionFindSet(size_t size) : _ufs(size, -1) {}

  //给一个元素进行编号，找到该元素所在集合的名称
  int FindRoot(int index) {
    //如果数组中存储的数字是负数，找到，否则一直继续
    while (_ufs[index] >= 0) {
      index = _ufs[index];
    }
    return index;
  }

  bool Union(int x, int y) {
    int root1 = FindRoot(x);
    int root2 = FindRoot(y);

    // x,y已经在一个集合
    if (root1 == root2) return false;
    // 将两个集合中元素合并
    _ufs[root1] += _ufs[root2];
    // 将其中一个集合名称改变成另外一个
    _ufs[root2] = root1;
    return true;
  }
  // 数组中负数的个数，即为集合的个数
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




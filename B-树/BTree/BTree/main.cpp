#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class T, size_t M = 3>
struct BTreeNode {
  BTreeNode() : _keys(M), _child(M + 1), _pParent(nullptr), _size(0) {}
  vector<T> _keys;
  vector<BTreeNode<T, M>>* _child;
  BTreeNode<T, M>* _pParent;
  size_t _size;
};

template <class T, size_t M = 3>
class BTree {
  typedef BTreeNode<T, M> Node;

 public:
  BTree() : _pRoot(nullptr) {}

  pair<Node*, int> Find(const T& key) {
    Node* cur = _pRoot;
    Node* pParent = nullptr;

    while (cur) {
      size_t i = 0;
      for (; i < cur->_size; ++i) {
        if (key < cur->_keys[i]) {
          break;
        } else if (key == cur->_keys[i]) {
          return make_pair(cur, i);
        }
      }
      pParent = cur;
      cur = cur->_child[i];
    }
    return make_pair(pParent, -1);
  }

  bool Insert(const T& k) {
    //空树
    if (_pRoot == nullptr) {
      _pRoot = new Node;
      _pRoot->_keys[0] = k;
      _pRoot->_size = 1;
      return true;
    }
    //非空
    // 1、找待插入节点的位置
    auto index = Find(k);
    if (-1 != index.second) {
      return false;
    }
    T key = k;
    Node* cur = index.first;  //叶子节点
    Node* Sub = nullptr;
    // 2、插入元素
    while (true) {
      //插入新节点
      InsertKey(cur, key, Sub);

      //如果插入节点后不满足B-树性质，进行分裂
      if (cur->_size != M) {
        return true;
      }

      //申请新节点
      Sub = new Node;

      //分裂，将中间元素以及右侧孩子节点搬移到新节点中
      size_t mid = (cur->_size >> 1);
      for (size_t i = mid + 1; i < cur->_size; ++i) {
        //搬移元素
        Sub->_keys[Sub->_size] = cur->_keys[i];
        //搬移孩子
        Sub->_child[Sub->_size++] = cur->_child[i];

        //更新孩子节点的双亲
        if (cur->_child[i]) {
          cur->_child[i]->_pParent = Sub;
        }
      }
      //孩子比关键字多搬移一个
      Sub->_child[Sub->_size] = cur->_child[cur->_size];

      //更新孩子节点的双亲
      if (cur->_child[cur->_size]) {
        cur->_child[cur->_size]->_pParent = Sub;
      }
      cur->_size -= (Sub->_size + 1);

      if (cur == _pRoot) {
        _pRoot = new Node;
        _pRoot->_keys[0] = cur->_keys[mid];
        _pRoot->_child[0] = cur;
        cur->_size = 1;

        _pRoot->_child[1] = Sub;
        cur->_pParent = Sub->_pParent = _pRoot;
        return true;
      } else {
        key = cur->_keys[mid];
        cur = cur->_pParent;
      }
    }
    return true;
  }
  void Inorder() { _InOrder(_pRoot); }

 private:
  void InsertKey(Node* cur, const T& key, Node* Sub) {
    int end = cur->_size - 1;
    while (end >= 0 && key < cur->_keys[end]) {
      //插入排序规则
      cur->_keys[end + 1] = cur->_size[end];

      //将该位置元素以及右侧孩子往右搬移一个位置
      cur->_child[end + 2] = cur->_child[end + 1];

      end--;
    }
    //插入新节点以及分裂出的新节点
    cur->_keys[end + 1] = key;
    cur->_child[end + 2] = Sub;

    //更新节点的双亲
    if (Sub) {
      Sub->_pParent = cur;
    }
    cur->_size++;
  }

  void _InOrder(Node* pRoot) {
    if (pRoot == nullptr) return;
    for (size_t i = 0; i < pRoot->_size; ++i) {
      _InOrder(pRoot->_child[i]);
      std::cout << pRoot->_keys[i] << " ";
    }
    _InOrder(pRoot->_child[pRoot->_size]);
    std::cout << std::end;
  }

 private:
  Node* _pRoot;
};

int main() {
  int array[] = {53, 139, 75, 49, 145, 36, 101};
  BTree<int> t;
  for (const auto& e : array) {
    t.Insert(e);
  }
  t.Inorder();
  return 0;
}
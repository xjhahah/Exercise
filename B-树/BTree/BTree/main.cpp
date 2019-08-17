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
    //����
    if (_pRoot == nullptr) {
      _pRoot = new Node;
      _pRoot->_keys[0] = k;
      _pRoot->_size = 1;
      return true;
    }
    //�ǿ�
    // 1���Ҵ�����ڵ��λ��
    auto index = Find(k);
    if (-1 != index.second) {
      return false;
    }
    T key = k;
    Node* cur = index.first;  //Ҷ�ӽڵ�
    Node* Sub = nullptr;
    // 2������Ԫ��
    while (true) {
      //�����½ڵ�
      InsertKey(cur, key, Sub);

      //�������ڵ������B-�����ʣ����з���
      if (cur->_size != M) {
        return true;
      }

      //�����½ڵ�
      Sub = new Node;

      //���ѣ����м�Ԫ���Լ��Ҳຢ�ӽڵ���Ƶ��½ڵ���
      size_t mid = (cur->_size >> 1);
      for (size_t i = mid + 1; i < cur->_size; ++i) {
        //����Ԫ��
        Sub->_keys[Sub->_size] = cur->_keys[i];
        //���ƺ���
        Sub->_child[Sub->_size++] = cur->_child[i];

        //���º��ӽڵ��˫��
        if (cur->_child[i]) {
          cur->_child[i]->_pParent = Sub;
        }
      }
      //���ӱȹؼ��ֶ����һ��
      Sub->_child[Sub->_size] = cur->_child[cur->_size];

      //���º��ӽڵ��˫��
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
      //�����������
      cur->_keys[end + 1] = cur->_size[end];

      //����λ��Ԫ���Լ��Ҳຢ�����Ұ���һ��λ��
      cur->_child[end + 2] = cur->_child[end + 1];

      end--;
    }
    //�����½ڵ��Լ����ѳ����½ڵ�
    cur->_keys[end + 1] = key;
    cur->_child[end + 2] = Sub;

    //���½ڵ��˫��
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
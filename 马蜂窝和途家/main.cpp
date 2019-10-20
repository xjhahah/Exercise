//;������
/*
�����ߵ�����

ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
��ʦס��ϲ�������Ͻ��µ�һ����ׯ��ͻȻһ�죬������ѩ�����ܿ��ׯ��Ҫ�����������˽������ѡ�
��ʦ���ܲ����ٶ�Ϊ13m/s,���������ٶȣ����޷�����ѩ���ġ����ǣ���ʦ���������ܣ�����1s���ƶ�50m,\
ÿ��ʹ�ü��ܺ󣬻�����10��ħ��ֵ��ħ��ֵ�Ļָ��ٶ�Ϊ4��/s,ֻ����ԭ����Ϣ״̬ʱ���ܹ��ָ���
����֪��ʦ��ʼֵΪM,����λ���밲ȫ����ľ���ΪS,ѩ�������ׯ��ʱ��ΪT��

��дһ�����򣬼��㷨ʦ�������̵�ʱ���ڵ��ﰲȫ�����粻�ܹ����ѣ������ʦ��ʱ�����ߵ���Զ���롣

����
����һ�У������ո�����������Ǹ�����M��S��T��
���
�������:


��1��Ϊ�ַ���"Yes"��"No" (���ִ�Сд)�����������Ƿ�������ĵ���

��2�а���һ����������һ��Ϊ"Yes" (���ִ�Сд��ʱ��ʾ����������ĵ������ʱ��

��һ��Ϊ"No" (���ִ�Сд) ʱ��ʾ���������ߵ���Զ���롣

��������
36 255 10
�������
Yes
10

��ʾ
30%����������: 1 <= T<= 10�� 1 <=S<= 100

50%����������: 1 <= T <= 1000�� 1 <= S <= 10000

100%����������: 1 <= T <= 300000�� 0 <= M<=1000 1 <=S <= 10^8
*/

#include <iostream>
#include <algorithm>

using namespace std;

int m, s, t, i, a, b;
int main() {
  cin >> m >> s >> t;  
  for (i = 1; i <= t; i++) {
    a += 13;  
    if (m >= 10) {
      m -= 10;  
      b += 50; 
    } else
      m += 4;  
    a = max(a, b);
    if (a >= s) {
      cout << "Yes" << endl << i;
      return 0;
    }
  }
  cout << "No" << endl << a;
  return 0;
}

/*
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
/*
34839946-beijing 34839946-shanghai 42342124-hongkong 42342124-guilin
42342124-guilin 12312344-shanghai 12312344-shanghai 22341234-nanjing �������
shanghai 2
beijing 1
guilin 1
*/
int main() {
  string s;
  while (getline(cin, s)) {
    map<std::pair<long long, string>, int> mp;
    string tmp = "";
    for (auto &e : s) {
      if (e != ' ') {
        tmp += e;
      } else {
        size_t pos = tmp.find('-');
        string str = tmp.substr(0, pos - 1);
        long long id = atoi(str.c_str());
        string ss = tmp.substr(pos + 1);

        mp[mp[id] = ss]++;
      }
    }
  }
  return 0;
}

#include <stdlib.h>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

struct BTreeNode {
  int val;
  BTreeNode *pLeft;
  BTreeNode *pRight;
  BTreeNode *pParent;
};

using namespace std;

BTreeNode *recoverFromPreorder(string S) {
  stack<BTreeNode *> st;
  int i = findNum(S, 0);
  BTreeNode *root = new BTreeNode(atoi(S.substr(0, i).c_str()));
  st.push(root);
  for (; i < S.size();) {
    int r = findDep(S, i);
    while (st.size() > r - i) st.pop();
    BTreeNode *node = st.top();
    int e = findNum(S, r);
    int num = atoi(S.substr(r, e - r).c_str());
    BTreeNode *tmp = new BTreeNode(num);
    if (node->pLeft) {
      node->pRight = tmp;
    } else {
      node->pLeft = tmp;
    }
    st.push(tmp);
    i = e;
  }
  return root;
}

int findNum(string &S, int i) {
  while (i < S.size() && S[i] >= '0' && S[i] <= '9') i++;
  return i;
}
int findDep(string &S, int i) {
  while (i < S.size() && S[i] == '-') i++;
  return i;
}

inline bool isRoot(BTreeNode *pNode) {
  if (nullptr == pNode) return false;
  return nullptr == pNode->pParent;
}

inline bool isLeft(BTreeNode *pNode) {
  if (nullptr == pNode) return false;
  if (nullptr != pNode->pParent) return pNode == pNode->pParent->pLeft;
  return false;
}

inline bool isRight(BTreeNode *pNode) {
  if (nullptr == pNode) return false;
  if (nullptr != pNode->pParent) return pNode == pNode->pParent->pRight;
  return false;
}

BTreeNode *GetNext(BTreeNode *pNode) {
  if (pNode == nullptr) return nullptr;

  // if this node has a right subtree
  if (nullptr != pNode->pRight) {
    auto pTemp = pNode->pRight;
    while (nullptr != pTemp->pLeft) {
      pTemp = pTemp->pLeft;
    }
    return pTemp;
  }

  // if this node doesn't have a right subtree
  else {
    if (isRoot(pNode))
      return nullptr;
    else if (isLeft(pNode))
      return pNode->pParent;
    else if (isRight(pNode)) {
      while (isRight(pNode)) pNode = pNode->pParent;
      if (isLeft(pNode))
        return pNode->pParent;
      else if (isRoot(pNode))
        return nullptr;
    }
  }

  return nullptr;
}
* /
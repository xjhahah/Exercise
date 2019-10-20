//途家名宿
/*
守望者的逃离

时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
法师住在喜马拉雅上脚下的一个村庄，突然一天，发生大雪崩，很快村庄就要被掩埋，所有人将会遇难。
法师的跑步的速度为13m/s,以这样的速度，是无法逃离雪崩的。但是，法师有闪跳技能，可在1s内移动50m,\
每次使用技能后，会消耗10点魔法值。魔法值的恢复速度为4点/s,只有在原地休息状态时才能够恢复。
现已知法师初始值为M,所在位置与安全区域的距离为S,雪崩到达村庄的时间为T。

编写一个程序，计算法师如何在最短的时间内到达安全区域，如不能够逃脱，输出法师在时间内走的最远距离。

输入
输入一行，包括空格隔开的三个非负整数M，S，T。
输出
输出两行:


第1行为字符串"Yes"或"No" (区分大小写)，即守望者是否能逃离荒岛。

第2行包含一个整数，第一行为"Yes" (区分大小写）时表示守望着逃离荒岛的最短时间

第一行为"No" (区分大小写) 时表示守望者能走的最远距离。

样例输入
36 255 10
样例输出
Yes
10

提示
30%的数据满足: 1 <= T<= 10， 1 <=S<= 100

50%的数据满足: 1 <= T <= 1000， 1 <= S <= 10000

100%的数据满足: 1 <= T <= 300000， 0 <= M<=1000 1 <=S <= 10^8
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
42342124-guilin 12312344-shanghai 12312344-shanghai 22341234-nanjing 样例输出
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
#include <iostream>
#include <string>

using std::string;


int main() {
  int n = 0;
  while (std::cin >> n) {
    while (n--) {
      string s;
      getline(std::cin, s);
      string s1 = "", s2 = "";
      size_t pos = s.find(' ');
      s1 += s.substr(0, pos);
      s2 += s.substr(pos + 1);
      int p1 = 0, p2 = 0;
      int num1 = 0, num2 = 0;
      bool flag = false;
      while (p1 < s1.size() || p2 < s2.size()) {
        while (p1 < s1.size() && s1[p1] != '.') {  //解析两个小数点之间的数字
          num1 = num1 * 10 + s1[p1] - '0';
          p1++;
        }
        while (p2 < s2.size() && s2[p2] != '.') {
          num2 = num2 * 10 + s2[p2] - '0';
          p2++;
        }
        if (num1 < num2) {
          flag = true;
        }
        if (num1 > num2) {
          flag = false;
          break;
        }
        num1 = 0;  //注意这里要置0
        num2 = 0;
        p1++;
        p2++;
      }
      if (flag) {
        std::cout << "true" << std::endl;
      } else {
        std::cout << "flase" << std::endl;
      }
    }
  }
  return 0;
}
#if 0
int main() {
  int n = 0;
  string s1, s2;
  while (getline(std::cin, s1)) {
    getline(std::cin, s2);
    int count = 0;
    int i = 0;
    string res = "";
    string tmp = "";
    for (auto& e : s2) {
      if (e != ' ') tmp += e;
    }
    for (int j = 0; j < s1.size(); ++j) {
      if (s1[j] == ' ') continue;
      count++;
      if (count < 5) {
        res += s1[j];
      } else {
        if (i < tmp.size()) {
          res += tmp[i];
          res += s1[j];
          i++;
          count = 1;
        }
      }
    }
    int len = tmp.size();
    if (i < len) {
      for (int j = i; j < len; ++j) {
        res += tmp[j];
      }
    }
    for (const auto& e : res) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

/*
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using std::unordered_set;
using std::string;
using std::vector;

int main() {
  int n = 0;
  while (std::cin >> n) {
    string s;
    vector<string> v;
    while (n--) {
      std::cin >> s;
      string tmp = "";
      for (auto& e : s) {
        if (e != ' ') {
          if (e != '.') {
            tmp += e;
		  }
		}
	  }
	}
  }
	return 0; 
}
*/


//平方和
bool isHappy(int n) {
  unordered_set<int> s;
  int sum = 0;
  while (n != 1) {
    s.insert(n);
    sum = 0;
    while (n != 0) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    n = sum;
    if (0 != s.count(n)) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 0;
  while (std::cin >> n) {
    int m = 0;
    while (n--) {
      std::cin >> m;
      bool flag = isHappy(m);
      if (flag) {
        std::cout << "true" << std::endl;
      } else {
        std::cout << "false" << std::endl;
      }
    }
  }
  return 0;
}

//360笔试
/*
题目描述：
将长N*M厘米的矩形区域划分成N行M列（每行每列的宽度均为1厘米），在第i行第j列的位置上叠放Ai,j个边长为1厘米的正方体（1≤Ai,j≤100），所有正方体就组成了一个立体图形，每个正方体六个面中的一部分会被其它正方体遮挡，未被遮挡的部分的总面积即为该立体图形的表面积，那么该立体图形的表面积是多少平方厘米
*/
/*
输入
第一行包含两个整数N和M，1≤N，M≤1000。
接下来N行，每行包含M个整数，第i行的第j个整数表示Ai,j。

输出
输出表面积的大小。

样例输入
2 2
2 1
1 1
样例输出
20
*/

int main() {
  int N, M;
  while (cin >> N >> M) {
    vector<vector<int>> vv(N + 2, vector<int>(M + 2, 0));
    int sum = 0;
    //上下表面积
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        cin >> vv[i][j];
        if (vv[i][j]) {
          sum += 2;
        }
      }
    }
    //侧面表面积
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        sum += vv[i][j] > vv[i - 1][j] ? vv[i][j] - vv[i - 1][j] : 0;
        sum += vv[i][j] > vv[i + 1][j] ? vv[i][j] - vv[i + 1][j] : 0;
        sum += vv[i][j] > vv[i][j - 1] ? vv[i][j] - vv[i][j - 1] : 0;
        sum += vv[i][j] > vv[i][j + 1] ? vv[i][j] - vv[i][j + 1] : 0;
      }
    }
    cout << sum << endl;
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::queue;
using std::string;
using std::vector;

//0-1背包问题
void fun(vector<int>& res, int m, int n) {
  if (m < n || n < 1 || (n == 1) && m != 1) {
    return;
  }
  if (m == n) {
    res[n] = 1;
    for (int i = 1; i <= n; ++i) {
      if (res[i]) {
        std::cout << i << " ";
	  }
	}
    std::cout << std::endl;
	res[n] = 0;
  }
  fun(res, m, n - 1);
  res[n] = 1;
  fun(res, m - n, n - 1);
  res[n] = 0;
}

int main() {
  int m, n;
  while (std::cin >> m >> n) {
    if (n > m) {
      n = m;
    }
    vector<int> res(n + 1, 0);
    fun(res, m, n);
  }
  return 0;
}


auto Fib(int n) {
  /*
if (n == 1) return 1;
if (n == 2) return 1;
return Fib(n - 1) + Fib(n - 2);*/
  auto first = 1ll;
  auto second = 1ll;
  auto third = 0ll;

  for (int i = 3; i <= n; ++i) {
    third = first + second;
    first = second;
    second = third;
  }
  return third;
}
int main() {
  int n = 10;
  std::cout << Fib(n) << std::endl;
  std::cout << sizeof(long) << " " << sizeof(long long) << std::endl;
	return 0; 
}

//打开转盘锁
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    //保存死亡列表
    std::unordered_set<string> deadSet(deadends.begin(), deadends.end());
    queue<string> q;
    //标记已经搜索过的
    std::unordered_set<string> book;
    if (deadSet.find("0000") != deadSet.end()) {
      return -1;
    }
    q.push("0000");
    book.insert("0000");
    int count = 0;
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        string cur = q.front();
        q.pop();

        if (cur == target) return count;
        for (int k = 0; k < 4; ++k) {
          string up = cur;
          string down = cur;
          up[k] = up[k] == '0' ? '9' : up[k] - 1;
          down[k] = down[k] == '9' ? '0' : down[k] + 1;
		  //已经存在或者没找到
          if (deadSet.find(up) == deadSet.end() &&
              book.find(up) == book.end()) {
            q.push(up);
            book.insert(up);
		  }
          if (deadSet.find(down) == deadSet.end() &&
              book.find(down) == book.end()) {
            q.push(down);
            book.insert(down);
          }
        }
      }
      count++;
    }
    return -1;
  }
};
// Employee info
//法二
class Employee {
 public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;
};
class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    if (employees.empty()) return 0;
    queue<int> q;
    std::unordered_map<int, Employee*> info;
  }
};

//法一
class Employee {
 public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;
};
class Solution {
 public:
  int DFS(std::unordered_map<int, Employee*>& info, int id) {
    int ret = info[id]->importance;
    for (auto& e : info[id]->subordinates) {
      ret += DFS(info, e);
    }
    return ret;
  }
  int getImportance(vector<Employee*> employees, int id) {
    if (employees.empty()) return 0;
    std::unordered_map<int, Employee*> info;

    for (auto& e : employees) {
      info[e->id] = e;
    }

    return DFS(info, id);
  }
};

int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

//岛屿数量
class Solution {
 public:
  void DFS(vector<vector<char>>& v, int row, int col, int x, int y,
           vector<vector<int>>& book) {
    book[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + pos[i][0];
      int ny = y + pos[i][1];
      if (nx >= row || nx < 0 || ny >= col || ny < 0) continue;
      if (v[nx][ny] == '1' && book[nx][ny] == 0) {
        DFS(v, row, col, nx, ny, book);
      }
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> book;
    book.resize(row);
    for (int i = 0; i < row; ++i) {
      book[i].resize(col, 0);
    }
    int num = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == '1' && book[i][j] == 0) {
          ++num;
          DFS(grid, row, col, i, j, book);
        }
      }
    }
    return num;
  }
};

int mian() {
  Solution s;
  return 0;
}

//被围绕的区域
class Solution {
 public:
  int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  void DFS(vector<vector<char>>& v, int row, int col, int x, int y) {
    v[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
      int nx = x + pos[i][0];
      int ny = y + pos[i][1];
      if (nx >= row || nx < 0 || ny >= col || ny < 0) continue;
      if (v[nx][ny] == 'O') {
        DFS(v, row, col, nx, ny);
      }
    }
  }
  void solve(vector<vector<char>>& v) {
    if (v.empty()) return;
    int row = v.size();
    int col = v[0].size();

	//第一行和最后一行
    for (int i = 0; i < col; ++i) {
      if (v[0][i] == 'O') {
        DFS(v, row, col, 0, i);
      }
      if (v[row - 1][i] == 'O') {
        DFS(v, row, col, row - 1, i);
      }
    }
	//第一列和最后一列
    for (int i = 0; i < row; ++i) {
      if (v[i][0] == 'O') {
        DFS(v, row, col, i, 0);
      }
      if (v[i][col - 1] == 'O') {
        DFS(v, row, col, i, col - 1);
      }
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (v[i][j] == '#')
          v[i][j] = 'O';
        else if (v[i][j] == 'O')
          v[i][j] = 'X';
      }
    }
  }
};




//分割回文串II
class Solution {
 public:
  int minCut(string s) {
    if (s.empty()) {
      return 0;
    }
    int cut[s.size() + 1];
    for (int i = 0; i <= s.size(); ++i) {
      cut[i] = i - 1;
    }

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (isPal(s, j, i - 1)) {
          cut[i] = std::min(cut[j] + 1, cut[i]);
        }
      }
    }
    return cut[s.size()];
  }
  bool isPal(string& s, int begin, int end) {
    while (begin < end) {
      if (s[begin] != s[end]) {
        return false;
      }
      ++begin;
      --end;
	}
    return true;
  }
};
//递归实现
class Solution {
 public:
  int minCut(string s) {
    if (s.empty()) {
      return 0;
    }
    int len = s.size();
    vector<int> cut;
    // F(i)初始化
    // F(0）= -1，必要项，如果没有这一项，对于重叠字符串“aaaaa”会产生错误的结果
    for (int i = 0; i < 1 + len; ++i) {
      cut.push_back(i - 1);
    }
    vector<vector<bool> > mat = getMat(s);
    for (int i = 1; i < 1 + len; ++i) {
      for (int j = 0; j < i; ++j) {
        // F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串
        // 从最长串判断，如果从第j+1到i为回文字符串
        // 则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串
        if (mat[j][i - 1]) {
          cut[i] = std::min(cut[i], 1 + cut[j]);
        }
      }
    }
    return cut[len];
  }
  vector<vector<bool> > getMat(string s) {
    int len = s.size();
    vector<vector<bool> > mat =
        vector<vector<bool> >(len, vector<bool>(len, false));
    for (int i = len - 1; i >= 0; --i) {
      for (int j = i; j < len; ++j) {
        if (j == i) {
          // 单字符为回文字符串
          mat[i][j] = true;
        } else if (j == i + 1) {
          // 相邻字符如果相同，则为回文字符串
          mat[i][j] = (s[i] == s[j]);
        } else {
          // F(i,j) = {s[i]==s[j] && F(i+1,j-1)
          // j > i+1
          mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);
        }
      }
    }
    return mat;
  }
};


class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> result;
    addOperatorsDFS(num, target, 0, 0, "", result);
    return result;
  }
  // lastOperaNum上一次添加的操作数（用于*法回退）
  void addOperatorsDFS(string num, int target, long long lastOperaNum,
                       long long curNum, string tempRes,
                       vector<string>& result) {
    if (num.size() == 0 && curNum == target) {  //此次运算符添加成功
      result.push_back(tempRes);
      return;
    }
    //对添加运算符的位置穷举
    for (int i = 1; i <= num.size(); ++i) {
      string cur = num.substr(0, i);
      if (cur.size() > 1 &&
          cur[0] == '0') {  //剪枝   cur不能出现“012”这种，即不能出现前导零
        return;
      }
      string next = num.substr(i);  // cur之后的字符串
      if (tempRes.size() > 0) {     //如果cur不是第一个操作数
        //尝试添加加，这次添加的操作数lastOperaNum == stoll(cur)
        addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur),
                        tempRes + "+" + cur, result);
        //尝试添加减，这次添加的操作数lastOperaNum == -stoll(cur)
        addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur),
                        tempRes + "-" + cur, result);
        //尝试添加乘
        //由于乘法的优先级比加、减法高，所以需要回退到上一步，即把上一步的操作数与乘法进行运算
        //这次添加的操作数lastOperaNum == lastOperaNum * stoll(cur)
        //(curNum - lastOperaNum)是退回上一次的操作数，然后在进行乘法运算   +
        // lastOperaNum * stoll(cur)
        addOperatorsDFS(next, target, lastOperaNum * stoll(cur),
                        (curNum - lastOperaNum) + lastOperaNum * stoll(cur),
                        tempRes + "*" + cur, result);
      } else {  //如果是第一个操作数
        addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, result);
      }
    }
  }
};

int main() {
  string s, t;
  while (std::cin >> s >> t) {
    string tmp = "";
    size_t i = 0;
    for (auto& e : t) {
      if (e == s[i] && i < s.size()) {
        tmp += e;
        i++;
      }
    }
    if (tmp.size() != s.size()) {
      std::cout << "No" << std::endl;
    } else {
      std::cout << "Yes" << std::endl;
    }
  }
  return 0;
}

//五子棋
#include <algorithm>
#include <exception>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  vector<vector<char>> checkBoard(20, vector<char>(20));
  char c;
  while (cin>>c) {
    //ungetc(c, stdin);
    for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < 20; ++j) {
        c = getchar();
        checkBoard[i][j] = c;
      }
      getchar();
    }

    bool found = false;
    for (int i = 0; i < 20; ++i) {
      if (found) break;
      for (int j = 0; j < 20; ++j) {
        if (checkBoard[i][j] == '.') continue;
        c = checkBoard[i][j];
        checkBoard[i][j] = '.';
        int curCount = 1;
        int x = i + 1;
        while (x < 20 && checkBoard[x][j] == c) {
          checkBoard[x][j] = '.';
          ++curCount;
          ++x;
        }
        if (curCount >= 5) {
          found = true;
          break;
        }
        curCount = 1;
        int y = j + 1;
        while (y < 20 && checkBoard[i][y] == c) {
          checkBoard[i][y] = '.';
          ++curCount;
          ++y;
        }
        if (curCount >= 5) {
          found = true;
          break;
        }
        curCount = 1;
        x = i + 1, y = j + 1;
        while (x < 20 && y < 20 && checkBoard[x][y] == c) {
          checkBoard[x][y] = '.';
          ++curCount;
          ++x;
          ++y;
        }
        if (curCount >= 5) {
          found = true;
          break;
        }
      }
    }

    if (found)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Emacs计算器
int main() {
  int n = 0;
  string s;
  while (std::cin >> n) {
    if (n < 3) return 0;
    std::cin.get();
    getline(cin, s);
    if (s.size() != (2 * n - 1)) return 0;
    
    stack<int> st;
    int sum = 0;
    // if (s.size() != n) return 0;
    for (auto& e : s) {
       if (e >= '0' && e <= '9') {
        st.push(e - '0');
      }
      if (e == '+' && st.size() >= 2) {
        int left = 0;
        left = st.top();
        st.pop();
        int right = st.top();
        st.pop();
        sum = right + left;
        st.push(sum );
        sum = 0;
        continue;
      } 
	  if (e == '-' && st.size() >= 2) {
        int left = 0;
        left = st.top();
        st.pop();
        int right = st.top();
        st.pop();
        sum = right - left;
        st.push(sum);
        sum = 0;
        continue;
      } 
	  if (e == '*' && st.size() >= 2) {
        int left = 0;
        left = st.top();
        st.pop();
        int right = st.top();
        st.pop();
        sum = right * left;
        st.push(sum);
        sum = 0;
        continue;
      }
	  if (e == '/' && st.size() >= 2) {
        int right = 0;
        right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        if (right == 0) {
          return 0;
        }
        sum = left / right;
        st.push(sum);
        sum = 0;
        continue;
      }
    }
    sum = st.top();
    st.pop();
    cout << sum << endl;
  }
  return 0;
}
//最长公共子序列
int main() {
  string A, B;
  while (cin >> A >> B) {
    int aLength = A.length();
    int bLength = B.length();
    vector<vector<int> > dp(aLength, vector<int>(bLength, 0));
    // 初始化边界
    dp[0][0] = (A[0] == B[0]) ? 1 : 0;
    for (int i = 1; i < aLength; i++) {
      dp[i][0] = (A[i] == B[0]) ? 1 : 0;
      dp[i][0] = max(dp[i - 1][0], dp[i][0]);
    }
    for (int j = 1; j < bLength; j++) {
      dp[0][j] = (A[0] == B[j]) ? 1 : 0;
      dp[0][j] = max(dp[0][j - 1], dp[0][j]);
    }
    // 计算
    for (int i = 1; i < aLength; i++) {
      for (int j = 1; j < bLength; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (A[i] == B[j]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }
    cout << dp[aLength - 1][bLength - 1] << endl;
  }

  return 0;
}



//字符串计数
int main() {
  string s1, s2;
  int len1, len2;
  while (cin >> s1 >> s2 >> len1 >> len2) {
    int result = 0;
    int dp[100001] = {0};
    for (int i = 1; i <= len2; i++) {
      dp[i] = (26 * (dp[i - 1])) % 1000007;
      if (i <= s1.size()) {
        dp[i] -= s1[i - 1];
      }
      if (i <= s2.size()) {
        dp[i] += s2[i - 1];
      }
      if (i == s2.size()) {
       dp[i]--;
	  }
      if (i >= len1) {
            result += dp[i];
          }
    }
    cout << result % 1000007 << endl;
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//背包问题
class Solution {
 public:
  /**
   * @param m: An integer m denotes the size of a backpack
   * @param A: Given n items with size A[i]
   * @param V: Given n items with value V[i]
   * @return: The maximum value
   */
  int backPackII(int m, vector<int> &A, vector<int> &V) {
    // write your code here

  }
};

//路径总数(Unique Paths II)
class Solution {
 public:
  int minPathSum(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty()) {
      return 0;
    }

    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    vector<vector<int>> pathNum(row, vector<int>(col, 0));

	pathNum[0][0] = obstacleGrid[0][0];

	//先处理边界情况
    for (int i = 1; i < row; ++i) {
          pathNum[i][0] = obstacleGrid[i][0] + pathNum[i - 1][0];
    }
    for (int i = 1; i < col; ++i) {
      pathNum[0][i] = obstacleGrid[0][i] + pathNum[0][i-1];
    }

	//在处理其他情况  
	//F(i,j) = min{F(i-1,j) , F(i,j-1)} + (i,j)
	for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; ++j) {
            pathNum[i][j] =
            obstacleGrid[i][j] + min(pathNum[i - 1][j], pathNum[i][j - 1]);
	  }
	}
        return pathNum[row - 1][col - 1];
  }
};

//路径总数(Unique Paths)
class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m < 0) {
      return 0;
    }
    vector<vector<int>> pathNum(m, vector<int>(n + 1, 1));
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
      }
    }
    return pathNum[m - 1][n - 1];
  }
};

//三角矩阵(Triangle)
class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    vector<vector<int>> minPath(triangle);

    for (int i = 1; i < triangle.size(); ++i) {
      minPath[i][0] = minPath[i - 1][0] + triangle[i][0];
      minPath[i][i] = minPath[i - 1][i - 1] + triangle[i][i];
    }

    for (int i = 2; i < triangle.size(); ++i) {
      for (int j = 1; j < i; ++j) {
        minPath[i][j] =
            min(minPath[i - 1][j], minPath[i - 1][j - 1]) + triangle[i][j];
      }
    }

    int row = triangle.size();
    int minRet = minPath[row - 1][0];
    for (int i = 1; i < row; ++i) {
      minRet = min(minPath[row - 1][i], minRet);
    }
    return minRet;
  }
};

// OP
class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    vector<vector<int>> minPath(triangle);

    int row = triangle.size();

    for (int i = row - 2; i >= 0; i--) {
      for (int j = 0; j <= i; ++j) {
        minPath[i][j] =
            min(minPath[i + 1][j], minPath[i + 1][j + 1]) + triangle[i][j];
      }
    }
    return minPath[0][0];
  }
};

#include <iostream>
using namespace std;

class A1 {
 public:
  void f1() {}

 private:
  //int _a;
};

int main() {
  cout << sizeof(A1) << endl;
  return 0;
}
//简单错误记录
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::vector;
using std::string;

string modifyName(string s) {
  int pos = s.find(' ');
  if (pos > 16) {
    s = s.substr(pos - 16);
  }
  return s;
}
int main() {
  string s;
  string line;
  vector<string> vs;
  vector<int> cnt;
  string tmp = "";
  int pos = 0;
  while (std::cin>>s>>line) {
    //1.找到最后一个\ 
	pos=s.find_last_of('\\');
    if (pos < 0) {
      break;
    }
    tmp = s.substr(pos + 1);
    tmp += ' ' + line;
    if (vs.empty() || std::find(vs.begin(), vs.end(), tmp) == vs.end()) {
      vs.push_back(tmp);
      cnt.push_back(1);
    } else {
      cnt[std::find(vs.begin(), vs.end(), tmp) - vs.begin()]++;
    }
  }
  size_t i = cnt.size() > 8 ? cnt.size() - 8 : 0;
  for (; i < cnt.size(); ++i) {
    std::cout << modifyName(vs[i]) << " " << cnt[i] << std::endl;
  }
  return 0;
}

#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

#define N 5

class Solution {
 public:
  int MoreThanHalfNum_Solution(vector<int> v) {
    map<int, int> mp;
    for (auto& e : v) {
      mp[e]++;
    }
    int len = v.size() / 2;
    for (auto& e : mp) {
      if (e.second > len) {
        return e.first;
      }
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> v(5, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> v[i];
  }
  std::cout << s.MoreThanHalfNum_Solution(v) << std::endl;
  return 0;
}

//查找兄度单词
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isBrother(string str, string s) {
  if (str.size() == s.size()) {
    if (str == s)
		return false;
    sort(str.begin(), str.end());
    sort(s.begin(), s.end());
    if (str == s) 
		return true;
  }
  return false;
}
int main() {
  int num;
  while (cin >> num) {
    string str;
    string word, s;
    int index;
    vector<string> vs;
    for (int i = 0; i < num; ++i) {
      cin >> str;
      vs.push_back(str);
    }
    sort(vs.begin(), vs.end());  // 因为是字典，一定要排序！！
    cin >> word;
    cin >> index;
    int counts = 0;

    for (int i = 0; i < num; ++i) {
      if (isBrother(word, vs[i])) {
        counts++;
        if (counts == index) s = vs[i];
      }
    }
    if (!vs.empty()) cout << counts << endl;
    if (counts >= index) cout << s << endl;
  }
  return 0;
}

//乒乓球筐
#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

int main() {
  string src, dst;
  while (std::cin >> src >> dst) {
    map<char, int> mp_src, mp_dst;
    bool flag = true;
    for (const auto& e : src) {
      mp_src[e]++;
    }
    for (const auto& e : dst) {
      mp_dst[e]++;
    }
    auto it = mp_dst.begin();
    while (it != mp_dst.end()) {
      if (mp_src[it->first] < it->second ) {
        flag = false;
        break;
      }
      it++;
    }
    if (flag) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}

//单词倒排
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
  string s;
  while (getline(std::cin, s)) {
    vector<string> res;
    string tmp = "";
    for (const auto& e : s) {
      if (e >= 'a' && e <= 'z' || e >= 'A' && e <= 'Z') {
        tmp += e;
      } else {
        if (tmp.size() > 0) {
          res.push_back(tmp);
          tmp.clear();
        }
      }
    }
    if (tmp.size() > 0) {
      res.push_back(tmp);
    }

    for (int i = res.size() - 1; i > 0; i--) {
      std::cout << res[i] << ' ';
    }
    std::cout << res[0] << std::endl;
  }
  return 0;
}

//驼峰命名法
#include <iostream>
#include <string>

using std::string;

int main() {
  string s;
  while (std::cin >> s) {
    string tmp = "";
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] != '_') {
        tmp += s[i];
      } 
	  else if (i != 0 && s[i] == '_') {
        i++;
        if (s[i] >= 'a' && s[i] <= 'z') {
          tmp += s[i] - 32;
        }
      }
    }
    std::cout << tmp << std::endl;
  }
  return 0;
}

//电话号码
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  string tmp = "22233344455566677778889999";
  int n = 0;
  while (cin >> n) {
    string s;
    set<string> res;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      int cnt = 0;
      string ss;
      for (auto& e : s) {
        if (e >= 'A' && e <= 'Z') {
          ss += tmp[e - 'A'];
          cnt++;
          if (cnt == 3) {
            ss += '-';
          }
        } else if (e >= '0' && e <= '9') {
          ss += e;
          cnt++;
          if (cnt == 3) {
            ss += '-';
          }
        }
      }
      res.emplace(ss);
    }
    for (const auto& phone : res) {
      cout << phone << endl;
    }
    cout << endl;
  }
  return 0;
}
/*
int main() {
  int n = 0;
  unordered_map<char, char> dic;
  dic.emplace('A', '2');
  dic.emplace('B', '2');
  dic.emplace('C', '2');
  dic.emplace('D', '3');
  dic.emplace('E', '3');
  dic.emplace('F', '3');
  dic.emplace('G', '4');
  dic.emplace('H', '4');
  dic.emplace('I', '4');
  dic.emplace('J', '5');
  dic.emplace('K', '5');
  dic.emplace('L', '5');
  dic.emplace('M', '6');
  dic.emplace('N', '6');
  dic.emplace('O', '6');
  dic.emplace('P', '7');
  dic.emplace('Q', '7');
  dic.emplace('R', '7');
  dic.emplace('S', '7');
  dic.emplace('T', '8');
  dic.emplace('U', '8');
  dic.emplace('V', '8');
  dic.emplace('W', '9');
  dic.emplace('X', '9');
  dic.emplace('Y', '9');
  dic.emplace('Z', '9');

  while (std::cin >> n) {
    string s;
    set<string> res;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      string ret = "";
      for (const auto& e : s) {
        if (isdigit(e)) {
          ret += e;
        } else if (isupper(e)) {
          ret += dic[e];
        }
      }
      if (ret.size() != 7) {
        continue;
      }
      ret = ret.substr(0, 3) + "-" + ret.substr(3);
      res.emplace(ret);
    }
    for (const auto& e : res) {
      std::cout << e << std::endl;
    }
    cout << endl;
  }
  return 0;
}
*/
#include <iostream>

int main() { 
	int n, m;
	while (std::cin >> n >> m) {
          for (int i = 1; i <= m / 2; ++i) {
            int j = i;
            int k = m - j;
            if (i < n && k < n) {
              std::cout << j << " " << k << std::endl;
			}
		  }
          std::cout << m << std::endl;
	}
	return 0; 
}

#include <cmath>
#include <iostream>

struct Num {
  long long up, down;
};

//最大公约数
long long Gcd(long long a, long long b) { return b == 0 ? a : Gcd(b, a % b); }

//化简
Num Simplification(Num& res) {
  if (res.down < 0) {
    res.up = -res.up;
    res.down = -res.down;
  } else if (res.up == 0) {
    res.down = 1;
  } else {
    //约分
    long long n = Gcd(abs(res.up), abs(res.down));
    res.up /= n;
    res.down /= n;
  }
  return res;
}

//实现 + - * /
Num Add(Num a, Num b) {
  Num res;
  res.up = a.up * b.down + b.up * a.down;
  res.down = a.down * b.down;
  return res;
}
Num Minu(Num a, Num b) {
  Num res;
  res.up = a.up * b.down - b.up * a.down;
  res.down = a.down * b.down;
  return res;
}
Num Mul(Num a, Num b) {
  Num res;
  res.up = a.up * b.up;
  res.down = a.down * b.down;
  return res;
}
Num Div(Num a, Num b) {
  Num res;
  res.up = a.up * b.down;
  res.down = a.down * b.up;
  return res;
}

void Print(Num n) {
  n = Simplification(n);  //化简一下
  if (n.up < 0) {
    std::cout << "(";
  }
  if (n.down == 1) {  //整数
    std::cout << n.up;
  } else if (abs(n.up) > abs(n.down))  //假分数
  {
    std::cout << n.up / n.down << " " << abs(n.up) % n.down << "/" << n.down;
  } else {
    std::cout << n.up << "/" << n.down;  //真分数
  }
  if (n.up < 0) {
    std::cout << ")";
  }
}

int main() {
  Num a, b;
  scanf_s("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

  Print(a);
  std::cout << " + ";
  Print(b);
  std::cout << " = ";
  Print(Add(a, b));
  std::cout << std::endl;

  Print(a);
  std::cout << " - ";
  Print(b);
  std::cout << " = ";
  Print(Minu(a, b));
  std::cout << std::endl;

  Print(a);
  std::cout << " * ";
  Print(b);
  std::cout << " = ";
  Print(Mul(a, b));
  std::cout << std::endl;

  Print(a);
  std::cout << " / ";
  Print(b);
  std::cout << " = ";
  if (b.up == 0) {
    std::cout << "Inf" << std::endl;
  } else {
    Print(Div(a, b));
    std::cout << std::endl;
  }
  return 0;
}
#endif
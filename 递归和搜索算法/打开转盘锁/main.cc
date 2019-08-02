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

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


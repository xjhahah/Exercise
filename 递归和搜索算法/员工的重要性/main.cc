class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		queue<int> q;
		q.push(id);
		unordered_map<int, Employee*> info;
		for (auto& e : employees)
		{
			info[e->id] = e;
		}
		int ret = 0;
		while (!q.empty())
		{
			int curId = q.front();
			q.pop();
			ret += info[curId]->importance;
			for (auto& subId : info[curId]->subordinates)
				q.push(subId);
		}
		return ret;
	}
};

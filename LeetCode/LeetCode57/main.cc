/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
示例 1:
	输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
	输出: [[1,5],[6,9]]
示例 2:
	输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
	输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };

class Solution {
public:
	vector<Interval> Insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		auto it = intervals.begin();
		while (it != intervals.end()) {
			if (newInterval.end < it->start) {
				intervals.insert(it, newInterval);
				return intervals;
			}
			else if (newInterval.start > it->end) {
				it++;
				continue;
			}
			else {
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it = intervals.erase(it);
			}
		}
		intervals.insert(intervals.end(), newInterval);
		return intervals;
	}
};
 */
class Solution {
public:
	vector<vector<int>> Insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end());

		result.push_back(intervals[0]);
		for (int i = 0; i < intervals.size(); ++i) {
			if (result.back().back() < intervals[i].front()) {
				result.push_back(intervals[i]);
			}
			else {
				result.back().back() = max(result.back().back(), intervals[i].back());
			}
		}
		return result;
	}
};
int main() {
	Solution s;
	vector<vector<int>> v1 = { {1,2},{3,5},{6,7},{8,12},{13,16} };
	vector<int> v2 = { 4,8 };
	vector<vector<int>> v=s.Insert(v1, v2);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.at(i).size(); ++j) {
			cout << v.at(i).at(j) << " ";
		}
		cout << endl;
	}
	return 0;
}


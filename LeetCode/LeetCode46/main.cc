#if 0
给定一个没有重复数字的序列，返回其所有可能的全排列。
示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
#endif

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return result;
    }
};

int main()
{
  Solution s;
  vector<int> v={1,2,3};
  vector<vector<int>> ret = s.permute(v);
  int i=0;
  for(auto& e :ret){
    for(auto& ee:e)
    {
      cout << ee;
    }
    cout << endl;
  }
  return 0;
}

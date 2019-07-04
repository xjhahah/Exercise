#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
  public:
    vector<vector<int> > threeSum(vector<int>& nums) {
      vector<vector<int> > res;
      sort(nums.begin(),nums.end());
      if(nums.empty() || nums.front() > 0 || nums.back() < 0)
        return {};
      for(int i = 0; i < nums.size();++i){
        if(nums[i] > 0)
          break;
        if(i > 0 && nums[i] == nums[i-1])
          continue;
        int target = 0 - nums[i];

        int left = i + 1 ;
        int right = nums.size()-1;

        while(left < right){
          if(nums[left] + nums[right] == target){
            res.push_back({nums[i],nums[left],nums[right]});
            while(left < right && nums[left] == nums[left+1])
            {
              ++left;
            }
            while(left < right && nums[right] == nums[right-1])
            {
              --right;
            }
            left++;
            right--;
          }
          else if(nums[left] + nums[right] < target){
            ++left;
          }
          else{
            --right;
          }
        }
      }
      return res;
    }
};
int main()
{
  Solution s;
  vector<int> v={-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ret = s.threeSum(v);
  for(int i=0;i < ret.size();++i){
    for(int j=0;j<3;++j){
      std::cout << ret[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

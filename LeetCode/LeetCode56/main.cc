#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
  public:
    //给出一个区间的集合，请合并出所有重叠的区间
    //[[a,b],[c,d],[e,f]]
    vector<vector<int>> merge(vector<vector<int>>& vec){
      if(vec.empty())
        return vec;
      vector<vector<int>> ret;
      ret.push_back(vec[0]); //将二维数组的第一组数据向push到ret中，便于下一步操作
      for(int i=1; i < vec.size(); ++i){
        if(ret.back().back() < vec[i].front()){ 
          //如果b<c,将vec[i]这一组数据push到ret中
          ret.push_back(vec[i]);
        }
        else{ //说明a>=b
          ret.back().back() = max(ret.back().back(),vec[i].back());
        }
      }
      return ret;
    }
};
int main()
{
  Solution s;
  vector<vector<int>> v={{1,3},{2,6},{8,10}};
  vector<vector<int>> vv=s.merge(v);
  for(int i=0;i<vv.size();++i)
  {
    cout << "[" ;
    for(int j=0;j<2;j++){
      cout << vv[i][j] << ",";
    }
    cout<<"],";
  }
  cout << endl;
  return 0;
}


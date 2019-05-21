//杨辉三角
#include <iostream>
#include <vector>

using std::vector;

//法一
/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows);
				//杨辉三角每一行的头和尾都是1，先将其初始化
        for(size_t i=1;i<=numRows;++i)
        {
            vv[i-1].resize(i,0);
            vv[i-1][0]=1;
            vv[i-1][i-1]=1;
        }
				//中间元素的值是上一行的左上角和右上角那两个元素之和（对角线的两个值）
        for(size_t i=0;i<vv.size();++i)
        {
            for(size_t j=0;j<vv[i].size()-1;++j)
            {
               if(vv[i][j]==0)
               {
                    vv[i][j]=vv[i-1][j-1]+vv[i-1][j];
               }
            }
        }
        return vv;
    }
};
*/
//法二
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>());
        for(int i=0;i<numRows;i++)
        {
            res[i].resize(i+1,1); //初始化每一行
            for(int j=1;j<i;j++)
            {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

int main()
{
  Solution s;
  int n=0;
  while(std::cin>>n){
    vector<vector<int>> v=s.generate(n);
    for(int i=0;i<n;++i){
      for(int j=0;j<=i;++j){
        std::cout << v[i][j];
      }
      std::cout << std::endl;
    }
  }
  return 0;
}

#if 0
给定一个正整数 n，你可以做如下操作：
1. 如果 n 是偶数，则用 n / 2替换 n。
2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
n 变为 1 所需的最小替换次数是多少？

示例 1:
输入:
8
输出:
3
解释:
8 -> 4 -> 2 -> 1
#endif

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/* 法一
class Solution{
  public:
    int integerReplacement(int n){
      int count = 0;
      while(n>1){
        if(n==3){
          count+=2;
          break;
        }
        if(n == INT32_MAX)
          return 32;
        if(!(n&1)){
          n>>=1;
        }
        else{
          if((n&2)==2){
            n++;
          }
          else{
            n--;
          }
        }
        count++;
      }
      cout << count << endl;
    }
};
*/

//法二:效率比法一高
class Solution {
public:
    int integerReplacement(int n) {
        int temp=0,res=0;
        while(n>1){
            if(n&1){
                temp++;
            }
            n>>=1;
            if(!(n&1)){
                temp>0?res++,temp>=2?n=n+1,temp=0:temp=0:temp=0;
            }
            res++;
        }
        return res+(temp>2?2:temp);
    }
};
int main()
{
  Solution s;
  int n;
  while(cin>>n){
   cout<< s.integerReplacement(n) << endl;
  }
	return 0;
}

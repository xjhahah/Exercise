#if 0
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:

输入: [2,2,3,2]
输出: 3
#endif

#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

/***********************************************
1、代码参考热评。解释下：假设有一个数为x,那么则有如下规律：
	0 ^ x = x,

	x ^ x = 0；

	x & ~x = 0,

	x & ~0 =x;

-那么就是很好解释上面的代码了。一开始a = 0, b = 0;

	1、x第一次出现后，a = (a ^ x) & ~b的结果为 a = x, b = (b ^ x) & ~a的结果为此时因为a = x了，所以b = 0。

	2、x第二次出现：a = (a ^ x) & ~b, a = (x ^ x) & ~0, a = 0; b = (b ^ x) & ~a 化简， b = (0 ^ x) & ~0 ,b = x;

	3、x第三次出现：a = (a ^ x) & ~b， a = (0 ^ x) & ~x ,a = 0; b = (b ^ x) & ~a 化简， b = (x ^ x) & ~0 , b = 0;所以出现三次同一个数，a和b最终都变回了0.
	只出现一次的数，按照上面x第一次出现的规律可知a = x, b = 0;因此最后返回a.
***********************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t a=0,b=0;
        for(const auto& e : nums){
            a=(a^e) & ~b;
            b=(b^e) & ~a;
        }
        return a;
    }
};

int main()
{
  Solution s;
  vector<int> v;
  int n=0;
  while(cin>>n){
    v.push_back(n);
  }
  cout << s.singleNumber(v) << endl;
  return 0;	
}

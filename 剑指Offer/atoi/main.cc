#if 0
题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
1a33
输出
2147483647
0
#endif

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int StrToInt(string str) {
        int i=0;
        int flag=1;
        size_t val=0;
        if(str[0]=='+' || str[0]=='-'){
            if(str[0]=='-')
            {
                flag=-1;
            }
            i++;
        }
        for(;i < str.size(); ++i){
            if(str[i] >= '0' && str[i] <= '9')
            {
                val=val*10+(str[i]-'0');
                if(val>INT32_MAX)
                {
                    return flag>0?INT32_MAX:INT32_MIN;
                }
            }
            else
                return 0;
        }
        return val*flag;
    }
};

int main()
{
  Solution s;
  string str;
  while(getline(cin,str)){
    cout << s.StrToInt(str) << endl;
  }
	return 0;
}

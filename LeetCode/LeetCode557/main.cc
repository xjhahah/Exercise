#if 0
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
#endif

#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution{
  public:
    string reverseStr(string s, int k) {
      size_t pos=0;
      while(s.size()-pos >= (2*k)){
        reverse(s.begin(),s.begin()+pos+k);
        pos += (2*k);
      }
      //小于2K但大于或等于K
      if(s.size()-pos >= k){
        reverse(s.begin()+pos,s.begin()+pos+k);
      }
      else{
        //小于K个字符
        reverse(s.begin()+pos,s.end());
      }
      return s;
    }
};
int main()
{
  Solution s;
  string str;
  int k;
  while(cin>>str>>k){
    cout << s.reverseStr(str,k) << endl;
  }
  return 0;
}

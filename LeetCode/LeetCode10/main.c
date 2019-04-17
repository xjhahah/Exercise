#if 0
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
#endif

#include <iostream>
#include <cstdio>

bool isMatch(const char*s,const char* p)
{
  if(*p == '\0')
    return *s == '\0';

  // next char is not '*', then must match current character
  if(*(p + 1) != '*'){
    if(*s == *p || (*p == '.' && *s != '\0')){
      return isMatch(s + 1, p + 1);
    }
    else 
      return false;
  }
  else{ //next char is '*'
    while(*s == *p || (*p == '.' && *s != '\0')){
      if(isMatch(s, p + 2))
          return true;
      s++;
  }
    return isMatch(s, p + 2);
  }
}

int main()
{
  char p[1024];
  char s[1024];
  while(std::cin>>s>>p)
  {
    bool ret = isMatch(s,p);
    std::cout << ret << std::endl;
  }
  return 0;
}

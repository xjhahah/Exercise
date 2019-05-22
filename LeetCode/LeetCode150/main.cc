#include <iostream>
#include <string>
#include <vector>
#include <stack>

using std::string;
using std::vector;
using std::stack;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i < tokens.size();++i)
        {
            string& str=tokens[i];
            
            if(!(str=="+" || str=="-" || str=="*" || str=="/"))
                 {
                     s.push(atoi(str.c_str()));
                 }
            else
                 {
                     int left=s.top();
                     s.pop();
                     int right=s.top();
                     s.pop();
                    switch(str[0])
                    {
                        case '+':
                            s.push(left+right);
                            break;
                        case '-':
                            s.push(right-left);
                            break;
                        case '*':
                            s.push(left*right);
                            break;
                        case '/':
                            s.push(right/left);
                            break;
                    }
                 }                
        }
        return s.top();
    }
};

int main()
{
  Solution s;
  vector<string> vs{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  std::cout << s.evalRPN(vs) << std::endl;
  return 0;
}

#if 0
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
	输入: 121
	输出: true
示例 2:
	输入: -121
	输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
#endif
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        ostringstream stream;
        stream<<x;
        string str=stream.str();
        string copy=str;
        reverse(str.begin(),str.end());
        return str==copy;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

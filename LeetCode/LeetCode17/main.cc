#if 0
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
#endif

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string> vec;
        if(digits.size() == 0)
            return vec;
        LetterCombinations(vec,0,"",mp,digits);
        return vec;
    }
    void LetterCombinations(vector<string>&vec,int i,string tmp,map<char,string> mp,string digits){
        if(tmp.size() == digits.size())
        {
            vec.push_back(tmp);
            return;
        }
        for(auto& c : mp[digits[i]]){
            LetterCombinations(vec,i+1,tmp+c,mp,digits);
        }
    }
};

int main()
{
	Solution s;
	string str;
	while(std::cin>>str){
		s.letterCombinations(str);	
	}
	return 0;
}

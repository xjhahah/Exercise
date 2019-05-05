#include <iostream>
#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int max=0;
        for(int i=s.size()-1;i>=0;i--){
            switch(s[i]){
                case 'I':
                    if(max>0)
                        sum-=1;
                    else
                        sum+=1;
                    break;
                case 'V':
                    max=5;
                    sum+=5;
                    break;
                case 'X':
                    if(max>10)
                        sum-=10;
                    else{
                        sum+=10;
                        max=10;
                    }
                    break;
                case 'L':
                    max=50;
                    sum+=50;
                    break;
                case 'C':
                    if(max>100)
                        sum-=100;
                    else
                    {
                        max=100;
                        sum+=100;
                    }
			        break;
                case 'D':
                    max=500;
                    sum+=500;
                    break;
                case 'M':
                    max=1000;
                    sum+=1000;
                    break;
                default:
                    cout << "data error!!!" <<endl;
                    break;
            }
        }
        return sum;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

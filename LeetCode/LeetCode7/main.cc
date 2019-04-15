#if 0
题目描述：
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:
输入: 123
	输出 : 321
示例 2 :
	输入 : -123
	输出 : -321
#endif

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int y = 0;
		while (x)
		{
			if (x > 0 && y <= (INT_MAX - x % 10) / 10 || x < 0 && y >= (INT_MIN - x % 10) / 10)
			{
				y = y * 10 + x % 10;
			}
			else
			{
				return 0;
			}
			x /= 10;
		}
		return y;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		int ret = Solution().reverse(x);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

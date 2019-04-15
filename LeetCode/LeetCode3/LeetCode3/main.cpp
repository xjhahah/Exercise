#if 0
����������
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
ʾ�� 1:
����: "abcabcbb"
	��� : 3
	���� : ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
#endif

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int i = 0, j = 0;
		int max = 0;
		for (; j < s.size(); ++j)
		{
			for (int k = i; k < j; ++k)
			{
				if (s[j] == s[k])
				{
					i = k + 1;
					break;
				}
			}
			if (j - i + 1 > max)
			{
				max = j - i + 1;
			}
		}

		return max;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
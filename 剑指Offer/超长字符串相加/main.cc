#include <iostream>
#include <string>
#include <algorithm>


using std::string;

int main()
{
	string s1, s2;
	while (std::cin >> s1 >> s2) {
		string ret;
		size_t next = 0;
		size_t sum = 0;
		const size_t length = s1.size() > s2.size() ? s1.size() : s2.size();
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		for (size_t i = 0; i < length; ++i) {
			const size_t left = (i < s1.size() ? s1[i] - '0' : 0);
			const size_t right = (i < s2.size() ? s2[i] - '0' : 0);
			sum = (left + right + next) % 10;
			next = (left + right + next) / 10;
			ret += (sum + '0');
		}
		if (next == 1) {
			ret += '1';
		}
		reverse(ret.begin(), ret.end());
		std::cout << ret << std::endl;
	}
	return 0;
}

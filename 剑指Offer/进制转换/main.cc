#include <iostream>
#include <string>
#include <cmath>

using std::string;

//任意进制到十进制的转换

int main()
{
	string s;
	int n = 0;
	while (std::cin >> s) {
		std::cout << "Please enter the process you want to convert: ";
		std::cin >> n;
		std::cout << std::endl;
		size_t res = 0;
		int tmp = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				res = res + (s[i] - '0' - 39) * pow(n, tmp);
			}
			else {
				res = res+(s[i] - '0') * pow(n, tmp);
			}
			tmp++;
		}
		std::cout << res << std::endl;
	}
	return 0;
}

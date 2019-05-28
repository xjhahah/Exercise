#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;

int main()
{
	int n = 0;
	std::cin >> n;
	while (n--) {
		string input, output;
		std::cin >> input;
		std::cin >> output;
		if (input.size() != output.size()){
			std::cout << "N" << std::endl;
			break;
		}
		auto begin = output.begin();
		auto end = output.end();

		stack<char> s;
		for (const auto& e : input) {
			s.push(e);
			while (!s.empty() && begin != end && *begin == s.top()) {
				begin++;
				s.pop();
			}
		}
		if (s.empty() && begin == end) {
			std::cout << "Y" << std::endl;
		}
		else
			std::cout << "N" << std::endl;
	}
	return 0;
}

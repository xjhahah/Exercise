#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <limits.h>
#include <map>

using namespace std;

int main()
{
	int n = 0;
	while (cin >> n) {
		map<int, int> m;
		vector<int> v;
		int data;
		for (int i = 0; i < n; ++i)
		{
			cin >> data;
			v.push_back(data);
		}
		for (int i = 0; i < n; ++i) {
			m[v[i]]++;
		}
		auto it = m.begin();
		int min = it->second;
		while (it != m.end())
		{
			if (m[it->first] < min)
			{
				min = m[it->first];
			}
			++it;
		}
		if (min ==1 || v.size() % min != 0)
		{
			cout << 0 << endl;
			break;
		}
		cout << v.size() / min << endl;
	}
	return 0;
}
#if 0
/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int string2int(string str) {
	int i = 0;
	int sign = 1;
	int val = 0;
	while (str[i] == ' ' && i < str.size()) {
		++i;
	}
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
		{
			sign = -1;
		}
		++i;
	}
	int j = 0;
	for (; i < str.size() && str[i] >= '0' && str[i] <= '9'; ++i) {
		j = i;
		val = val * 10 + (str[i] - '0');
		if (val >= INT_MAX)
		{
			return sign > 0 ? INT_MAX : INT_MIN;
		}
	}

	return val * sign;
}
/******************************结束写代码******************************/


int main() {
	int res;

	string _str;
	while (getline(cin, _str)) {

		res = string2int(_str);
		cout << res << endl;
	}
	return 0;

}


#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = { -1,2,-1,3,4,5 };
	int maxSum = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < vec.size(); ++i) 
	{

		if (maxSum <= 0)
		{
			maxSum = vec[i];
			start = i;
			if (maxSum <= 0 && i == vec.size() - 1)
			{
				end = i;
			}
		}
		else
		{
			maxSum += vec[i];
			end = i;
		}
	}
	std::cout << maxSum << " " << start << " " << end << std::endl;
	return 0;
}



#include <iostream>
#include <set>
#include <math.h>

using namespace std;

bool SuShu(int n)
{
	for (int j = 2; j < sqrt(n); ++j)
	{
		if (n%j != 0)
		{
			return true;
		}
		return false;
	}
	return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		/*
		int k = 0;
		for (int i = 2; i <= sqrt(n); i++)
			if (n%i == 0)
			{
				while (n%i == 0)
				{
					n = n / i;
					k++;
				}
			}
		if (n != 1)
		{
			k++;
		}
		cout << k << endl;
	}
	*/
	int num=0;
	set<int> m;
	for(int i=2;i<n;++i)
	{
		num=n%i;
		if(num==0)
		{
			if(i<10)
			{
				m.insert(i);
				continue;
			}
			else
			{
				if (SuShu(i))
				{
					m.insert(i);
					continue;
				}
				else 
				{
					for (int j = 2; j < i; ++j)
					{
						if (i%j == 0)
						{
							m.insert(j);
						}
					}
				}
				
			}
		}
	}
	cout << " ";
	cout << m.size() << endl;
}
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	while (1)
	{
		vector<int> vec;
		for (int i = 0; i < 3; i++)
		{
			int num = 0;
			cin >> num;
			vec.push_back(num);
		}
		if (((vec[0] + vec[1]) > vec[2]) && ((vec[0] + vec[2]) > vec[1]) && ((vec[1]+vec[2]) > vec[0]))
		{
			cout << "Yes" << endl;
			continue;
		}
		else
		{
			cout << "No" << endl;
			continue;
		}
	}
	return 0;
}
#endif
/*
void Safelevel(string s)
{
	int len = s.size();
	static int count = 0;
	static int numsize = 0;
	static int zsize = 0;
	static int Zsize = 0; //大写字母个数
	static int fuhao = 0;

	if (len > 0 && len <= 4)
		count += 5;
	else if (len <= 7)
		count += 10;
	else
		count += 25;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			numsize++;
		}
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			zsize++;  //小写字母
		}
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			Zsize++;
		}
		if ((s[i] >= 0x21 && s[i] <= 0x2F) || (s[i] >= 0x3A && s[i] <= 0x40) ||
			(s[i] >= 0x5B && s[i] <= 0x60) || (s[i] >= 0x7B && s[i] <= 0x7E))
		{
			fuhao++;
		}
	}
	//统计各种符号出现次数的分值
	if (zsize == len || Zsize == len)
		count += 10;
	else if (zsize > 0 && Zsize > 0)
		count += 20;
	else count += 0;
	if (numsize == 1)
		count += 10;
	else if (numsize > 1)
		count += 20;
	else
		count += 0;
	if (fuhao == 1)
		count += 10;
	else if (fuhao > 1)
		count += 25;
	else
		count += 0;

	//计算奖励
	if (numsize > 0 && zsize > 0 && Zsize > 0 && fuhao > 0)
		count += 5;
	if ((zsize > 0 && numsize > 0) || (Zsize > 0 && numsize > 0))
		count += 2;
	if ((zsize > 0 && numsize > 0 && fuhao > 0) || (Zsize > 0 && numsize > 0 && fuhao > 0))
		count += 3;

	if (count >= 90)
		cout << "VERY_SECURE" << endl;
	else if (count >= 80)
		cout << "SECURE" << endl;
	else if (count >= 70)
		cout << "VERY_STRONG" << endl;
	else if (count >= 60)
		cout << "STRONG" << endl;
	else if (count >= 50)
		cout << "AVERAGE" << endl;
	else if (count >= 25)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;
}
int main()
{
	string s;
	s = "12$@abAb";
	Safelevel(s);
	return 0;

}
*/

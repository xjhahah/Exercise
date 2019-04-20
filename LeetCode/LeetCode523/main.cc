#if 0
题目描述：
求一个数组中最大的连续子序列的和，并返回该序列的起始位置和终止位置。
例如：vec = { -1,2,-1,3,4,5 };
      输出：最大和：13，起始位置：1，终止位置：5
#endif

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
			if (maxSum <= 0 && i == vec.size() - 1) //如果全是负数
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

#if 0
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
#endif

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


//解法二
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        const int m=A.size();
        const int n=B.size();
        
        int total = n+m;
        if(total & 0x1){
            return find_kth(A.begin(),m,B.begin(),n,total/2+1);
        }
        else{
            return (find_kth(A.begin(), m, B.begin(), n, total / 2) + find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
        }
    }
private:
    static int find_kth(vector<int>::const_iterator A,int m,vector<int>::const_iterator B,int n,int k){
        if(m>n){
            return find_kth(B,n,A,m,k);
        }
        if(m==0){
            return *(B+k-1);
        }
        if(k==1){
            return min(*A,*B);
        }
        
        int ia=min(k/2,m),ib=k-ia;
        if(*(A+ia-1) < *(B+ib-1)){
            return find_kth(A+ia,m-ia,B,n,k-ia);
        }
        else if(*(A+ia-1) > *(B+ib-1)){
            return find_kth(A,m,B+ib,n-ib,k-ib);
        }
        else{
            return A[ia-1];
        }
    }
};

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
		auto left = nums1.begin();
		auto right = nums2.begin();
		int size = nums1.size() + nums2.size();
		int sum = 0;
		int temp = 0; 
		int temp1 = 0;
		for (int i = 0; i <= size / 2; i++)
		{	
			if (left == nums1.end())
				temp = *right++;
			else if (right == nums2.end())
				temp = *left++;
			else if (*left < *right)
				temp = *left++;
			else
				temp = *right++;
			if (size / 2 - 1 == i)
			{
				temp1 = temp;
			}
		}
		if (size % 2 != 0)
		{
			return temp;
		}
		else
		{
			return (temp + temp1) / 2.0;
		}

	}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

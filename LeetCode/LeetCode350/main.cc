#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ret;
        for(int e : nums1){
            m[e]++;
        }
        for(int e : nums2){
            if(m.find(e) != m.end() && (m[e]--)>0){
                ret.push_back(e);
            }
        }
        return ret;
    }
};

int main()
{
	Solution s;
  vector<int> v1{1,2,2,1};
  vector<int> v2{2,2};
  int n,m;
  vector<int> v=s.intersect(v1,v2);
  for(auto e : v)
  {
    cout << e << " ";
  }
  cout << endl;
	return 0;
}

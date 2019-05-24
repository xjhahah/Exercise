#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class Solution{
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int,int> m;
      for(const auto& e : nums){
        m[e]++;
      }

      priority_queue<pair<int,int>> pq;
      for(auto it = m.begin();it != m.end();++it){
        pq.push(make_pair(it->second,it->first));
      }
      vector<int> res;
      for(int i=0; i < k;++i){
        res.push_back(pq.top().second);
        pq.pop();
      }
      return res;
    }
};
int main()
{
  Solution s;
  vector<int> v={1,2,3,4,1,2,1};
  vector<int> res = s.topKFrequent(v,2);
  for(const auto& e:res){
    cout << e <<" ";
  }
  cout<<endl;
  return 0;
}


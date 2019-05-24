#include <iostream>
#include <map>
#include <queue>
#include <vector>

using std::vector;
using std::queue;
using std::map;


class Solution {
public:
    struct cmp{
      bool operator() (pair<string,int> a,pair<string,int> b){
          if(a.second == b.second)
              return a.first<b.first;
          return a.second>b.second;
      }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(const auto& e : words){
            mp[e]++;
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
        for(auto it = mp.begin();it!=mp.end();++it){
            if(pq.size() < k){
                pq.push(make_pair(it->first,it->second));
            }
            else{
                if(pq.top().second < it->second){
                    pq.pop();
                    pq.push(make_pair(it->first,it->second));
                }
            }
            
        }
        vector<string> res;
        for(int i=0;i<k;++i){
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
	Solution s;
	
	return 0;
}

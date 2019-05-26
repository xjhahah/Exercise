#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
  void func(string& s,unordered_map<string,int>& mp){
    string cur;
    int begin=0;
    int end=0;
    do{
      end=s.find(' ',begin);
      cur=s.substr(begin,end-begin);
      mp[cur]++;
      begin=end+1;
    }while(-1!=end);
  }
    vector<string> uncommonFromSentences(string A, string B) {
      vector<string> v;
      unordered_map<string,int> mp;

      func(A,mp);
      func(B,mp);

      for(const auto& e:mp){
        if(1==e.second){
          v.push_back(e.first);
        }
      }
      return v;
    }
};

int main()
{
  Solution s;
  string s1;
  string s2;
  getline(std::cin,s1);
  getline(std::cin,s2);

  vector<string> vs=s.uncommonFromSentences(s1,s2);
  for(const auto& e : vs){
    std::cout << e << " ";
  }
  std::cout<<std::endl;
  return 0;
}

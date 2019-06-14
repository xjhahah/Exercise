#include <iostream>
#include <string>
#include <algorithm>

using std::string;

int main()
{
  string s1,s2;
  while(std::cin>>s1>>s2){
    if(s1.size()>s2.size()){
      std::swap(s1,s2);
    }
    string ret;
    for(int i=0;i < s1.size();++i){
      for(int j=i;j < s1.size();++j){
        string tmp=s1.substr(i,j-i+1);
        if(int(s2.find(tmp)) < 0){
          break;
        }
        else if(ret.size() < tmp.size()){
          ret = tmp;
        }
      }
    }
    std::cout << ret << std::endl;
  }
  return 0;
}

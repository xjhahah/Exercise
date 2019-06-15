#include <iostream>
#include <string>

using std::string;

int main()
{
  string s;
  while(std::cin>>s){
    if(s.empty())
      return 0;
    size_t start=0;
    size_t end=s.size()-1;
    while(start < end){
      std::swap(s[start],s[end]);
      start++;
      end--;
    }
    std::cout << s << std::endl;
  }
  return 0;
}

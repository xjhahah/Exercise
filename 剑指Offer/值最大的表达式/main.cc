#include <iostream>
#include <vector>
#include <algorithm>

/*
给出三个正整数a， b 和 c，你可以在它们之间插入加号或者乘号以及括号将其变成一个表达式。比如给出
i 1， 2 和 3，你可以构造出：
1+2*3=7
1*(2+3)=5
1*2*3=6
(1+2)*3=9
等表达式。现在你需要构造一个值最大的表达式，输出这个值。
 */

using std::vector;


int main()
{
  int a,b,c;
  while(std::cin>>a>>b>>c){
    int ret=0;
    vector<int> v;
    ret=a+b+c;
    v.push_back(ret);

    ret=a+(b*c);
    v.push_back(ret);

    ret=(a+b)*c;
    v.push_back(ret);

    ret=a*(b+c);
    v.push_back(ret);

    ret=(a*b)+c;
    v.push_back(ret);

    ret=a*b*c;
    v.push_back(ret);

    std::sort(v.begin(),v.end());
    for(auto& e : v){
      std::cout << e << " ";
    }
    std::cout<<"\n";
    std::cout << v[v.size()-1] << std::endl;
  }
  return 0;
}

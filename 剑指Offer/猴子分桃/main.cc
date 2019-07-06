#include <iostream>
#include <cmath>

int main()
{
  int n=0;
  while(std::cin>>n){
    if(n == 0){
      break;
    }
    int total = pow(5,n) - 4; //最少需要的桃子数
    int left = pow(4,n) + n -4; //老猴子最后能够分到的桃子数
    std::cout << "total : " << total << "; left: " << left << std::endl;
  }
  return 0;
}

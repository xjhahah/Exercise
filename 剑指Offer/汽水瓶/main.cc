#include <iostream>

int func(int n){
  int count=0;
  while(n>1){
    int res=n/3;
    int mod=n%3;
    
    count = count + res;

    n=res+mod;

    if(n==2){
      ++count;
      break;
    }
  }
  return count;
}
int main()
{
  int n=0;
  while(std::cin>>n){
    if(n==0){
      break;
    }
    else{
      std::cout << func(n) << std::endl;
    }
  }
  return 0;
}

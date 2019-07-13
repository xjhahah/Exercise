#include <iostream>
#include <cstdio>

double Molecule(int n){
  if(n == 1){
    return 0;
  }
  else if(n == 2){
    return 1;
  }
  else{
    return (n-1)*(Molecule(n-1) + Molecule(n-2));
  }
}

//分母
double Denominator(int n){
  if(n==0){ // 0！=1
    return 1;
  }
  else{
    return n*Molecule(n-1);
  }
}
int main()
{
  int n=0;
  while(std::cin>>n){
    double res = (Molecule(n) / Denominator(n)) * 100;
    printf("%.2f%%\n",res);
  }
  return 0;
}

#include <iostream>
#include <vector>

using std::vector;

int getFirstUnFormedNum(vector<int> arr, int len)
{
  int min = arr[0];
  int max = 0;
  int i,j;
  for(const auto& e : arr){
    if(e < min)
      min = e;
    max += e;
  }

  vector<int> dp(max+1,0);

  for(int i = 0;i < len;++i){
    for(int j = max;j >= arr[i]; j--){
      if(dp[j-arr[i]] + arr[i] > dp[j]){
        dp[j] = dp[j-arr[i]] + arr[i];
      }
      else{
        dp[j] = dp[j];
      }
    }
  }
  for(i = min;i <= max;++i){
    if(i != dp[i])
      return i;
  }
  return i;
}

int main()
{
  int n=0;
  while(std::cin>>n){
    vector<int> v(n,0);
    while(n--){
      std::cin>>v[n];
    }
    std::cout << getFirstUnFormedNum(v,v.size()) << std::endl;
  }

  return 0;
}

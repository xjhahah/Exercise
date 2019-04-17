#if 0
知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。
输入描述:
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区间)。
输出描述:
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
示例1
输入
1 -2 3 4
输出
2 1 3
#endif
#include <iostream>

int main()
{
    int a,b,c,d;
    std::cin>>a>>b>>c>>d;
    
    int A=(a+c)>>1;
    int B1=(c-a)>>1;
    int B2=(b+d)>>1;
    int C=(d-b)>>1;
    
    if(B1!=B2){
        std::cout<<"No";
    } 
    else{
        std::cout<<A<<" "<<B1<<" "<<C;
    } 
    return 0;
}

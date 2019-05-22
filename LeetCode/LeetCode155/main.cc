#include <iostream>
#include <stack>

using std::stack;

#if 0
class Solution{
  private:
    //法一：一个栈实现最小栈
    stack<int> st;
  public:
    /** initialize your data structure here. */
    Solution() {

    }  

    void push(int x) {
      if(st.empty()){
        st.push(x);
        st.push(x);
      }
      else{
        int tmp=st.top();
        st.push(x);
        if(tmp<x){
          st.push(tmp);
        }
        else{
          st.push(x);
        }
      }
    }
        
    void pop() {
        st.pop();
        st.pop();
    }
        
    int top() {
      int tmp=st.top();
      st.pop();
      int top = st.top();
      st.push(tmp);
      return top;
    }
        
    int getMin() {
      return st.top();
    }
};
#endif

//法二：用两个栈实现最小栈
class Solution {
public:
    /** initialize your data structure here. */
    Solution() {
        
    }
    
    void push(int x) {
      st.push(x);
      if(min.empty() || x <= min.top()){
        min.push(x);
      }
    }
    
    void pop() {
      if(st.top() == min.top()){
        min.pop();
      }
      st.pop();
    }
    
    int top() {
       return st.top(); 
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> st; //数据栈
    stack<int> min; //临时栈
};
int main()
{
  Solution s;
  s.push(1);
  s.push(3);
  s.push(5);
  s.push(7);

  
  std::cout << s.top() << std::endl;
  std::cout << s.getMin() << std::endl;
  
  s.pop();

  std::cout << s.top() << std::endl;
  std::cout << s.getMin() << std::endl;

  return 0;
}

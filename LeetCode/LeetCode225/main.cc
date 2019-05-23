#include <iostream>
#include <queue>

using std::queue;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);
        while(!q.empty()){
            tmp.push(q.front());
            q.pop();
        }
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp=q.front();
        q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

int main()
{
  MyStack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);

  std::cout << s.top() << std::endl;
  std::cout << s.empty() <<std::endl;

  s.pop();
  std::cout << s.top() << std::endl;
  std::cout << s.empty() <<std::endl;
  
  s.pop();
  s.pop();
  s.pop();
  std::cout << s.top() << std::endl;
  std::cout << s.empty() <<std::endl;

  return 0;
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

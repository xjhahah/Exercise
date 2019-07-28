#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Emacs计算器
int main() {
  int n = 0;
  string s;
  while (std::cin >> n) {
    if (n < 3) return 0;
    std::cin.get();
    getline(cin, s);
    if (s.size() != (2 * n - 1)) return 0;
    
    stack<int> st;
    int sum = 0;
    // if (s.size() != n) return 0;
    for (auto& e : s) {
       if (e >= '0' && e <= '9') {
        st.push(e - '0');
      }
      if (e == '+' && st.size() >= 2) {
        int left = 0;
        left = st.top();
        st.pop();
        int right = st.top();
        st.pop();
        sum = right + left;
        st.push(sum );
        sum = 0;
        continue;
      } 
	  if (e == '-' && st.size() >= 2) {
        int left = 0;
        left = st.top();
        st.pop();
        int right = st.top();
        st.pop();
        sum = right - left;
        st.push(sum);
        sum = 0;
        continue;
      } 
	  if (e == '*' && st.size() >= 2) {
        int left = 0;
        left = st.top();
        st.pop();
        int right = st.top();
        st.pop();
        sum = right * left;
        st.push(sum);
        sum = 0;
        continue;
      }
	  if (e == '/' && st.size() >= 2) {
        int right = 0;
        right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        if (right == 0) {
          return 0;
        }
        sum = left / right;
        st.push(sum);
        sum = 0;
        continue;
      }
    }
    sum = st.top();
    st.pop();
    cout << sum << endl;
  }
  return 0;
}

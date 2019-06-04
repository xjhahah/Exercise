//用单调栈解决该问题，相对简单
/*
具体解决思路参考：https://blog.csdn.net/Zolewit/article/details/88863970
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        v.push_back(0);
        stack<int> s;
        int maxArea=0;
        for(int i=0;i<v.size();++i){
            while(!s.empty() && v[i] < v[s.top()]){
                int top=s.top();
                s.pop();
                maxArea = max(maxArea,v[top]*(s.empty() ? i : (i - s.top() -1)));
            }
            
            s.push(i);
        }
        return maxArea;
    }
};

//法二
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
        
        for(int i=1;i<n;++i){
            left[i] = max(left[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i+1]);
        }
        
        int count=0;
        for(int i=0;i<n;++i){
            int min_num = min(left[i],right[i]);
            count+=max(0,min_num-height[i]);
        }
        return count;
    }
};

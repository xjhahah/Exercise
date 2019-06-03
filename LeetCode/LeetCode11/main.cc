class Solution {
public:
    int maxArea(vector<int>& v) {
        if(v.empty())
            return -1;
        int Max=0;
        int start=0;
        int end=v.size()-1;
        
        while(start < end){
            int min_height=((v[start]>v[end])?v[end]:v[start]);
            Max = (Max > (min_height*(end-start)) ? Max : (min_height*(end-start)));
            if(v[start] < v[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return Max;
    }
};

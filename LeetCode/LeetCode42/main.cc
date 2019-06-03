//法一：效率比用两个vector高
class Solution {
public:
    int trap(vector<int>& v) {
        int Max = 0;
        if(v.empty())return 0;
        for(int i = 1;i < v.size(); i++)
        {
            Max = v[i]>v[Max]?i:Max;
        }
        int ret = 0;
        int sm = v[0];
        for(int i = 0; i < Max; i++)
        {
            ret += sm>v[i]?sm-v[i]:0;
            sm = max(v[i],sm);
        }
        sm = v[v.size()-1];
        for(int i = v.size()-1;i>Max;i--)
        {
            ret += sm>v[i]?sm-v[i]:0;
            sm = max(v[i],sm);
        }
        return ret;
    }
};

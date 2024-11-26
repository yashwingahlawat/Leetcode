class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        bool b=0;
        long long ans=0;
        for(auto i:matrix){
            for(auto j:i){
                if(j<0)b=!b;
                mini=min(mini,abs(j));
                ans+=abs(j);
            }
        }
        if(b)ans-=2*mini;
        return ans;
    }
};
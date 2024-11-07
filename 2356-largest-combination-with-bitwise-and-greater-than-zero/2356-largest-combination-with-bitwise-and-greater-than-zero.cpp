class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(auto j:candidates){
                if(j&(1<<i))c++;
            }
            res=max(c,res);
        }
        return res;
    }
};
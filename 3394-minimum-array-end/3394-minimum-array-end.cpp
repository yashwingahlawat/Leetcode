class Solution {
public:
    long long minEnd(int n, int x) {
        int val=n-1;
        vector<int>res;
        while(val>0 || x>0){
            if(x&1){
                res.push_back(x&1);
                x=x>>1;
            }
            else {
                res.push_back(val&1);
                val=val>>1;
                x=x>>1;
            }
        }
        long long ab=0;
        reverse(res.begin(),res.end());
        for(auto i:res){
            ab=ab<<1;
            ab=ab|i;
        }
        return ab;
    }
};
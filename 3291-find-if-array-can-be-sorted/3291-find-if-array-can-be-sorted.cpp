class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>store;
        for(auto i:nums){
            int x=i;
            int z=0;
            while(x>0){
                z+=x&1;
                x>>=1;
            }
            store.push_back({i,z});
        }
        for(int i=0;i<store.size();i++){
            bool b=0;
            for(int j=i+1;j<store.size();j++){
                if(store[i].first>store[j].first && (store[i].second!=store[j].second || b!=0))return 0;
                else if(store[i].second!=store[j].second)b=1;
            }
        }
        return 1;
    }
};
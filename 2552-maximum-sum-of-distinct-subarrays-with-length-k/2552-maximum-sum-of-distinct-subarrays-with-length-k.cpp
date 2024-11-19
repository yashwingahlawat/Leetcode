class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>q;
        // for(auto i:nums)q[i]++;
        // for(auto i:q)cout<<i.first<<" "<<i.second<<" | ";
        long long res=0;
        int i=0,j=0;
        long long val=0;
        if(k==1){
            int res=0;
            for(auto i:nums)res=max(res,i);
            return res;
        }
        while(i<nums.size() && j<nums.size()){
            q[nums[i]]++;
            val+=nums[i];
            while(j<nums.size() && q[nums[i]]>1){
                q[nums[j]]--;
                val-=nums[j];
                j++;
            }
            cout<<i<<" "<<j<<" "<<val<<endl;
            if(i-j+1==k){
                res=max(res,val);
                val-=nums[j];
                q[nums[j]]--;
                j++;
            }
            i++;
        }
        return res;
    }
};
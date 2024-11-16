class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>res;
        if(k==1)return nums;
        for(int i=0;i<nums.size()-k+1;i++){
            int temp=-1;
            for(int j=i;j<i+k-1;j++){
                if(nums[j]+1!=nums[j+1]){
                    temp=-1;
                    break;
                }
                temp=nums[j+1];
            }
            res.push_back(temp);
        }
        return res;
    }
};
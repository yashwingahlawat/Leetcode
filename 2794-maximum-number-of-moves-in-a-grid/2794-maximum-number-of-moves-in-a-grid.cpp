class Solution {
public:
    int solve(int i,int j,int prev,vector<vector<int>>&nums,vector<vector<int>>&dp){
        if(nums.size()==i || nums[0].size()==j || i==-1 || j==-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(nums[i][j]>prev){
            return dp[i][j]=1+max(solve(i-1,j+1,nums[i][j],nums,dp),max(solve(i+1,j+1,nums[i][j],nums,dp),solve(i,j+1,nums[i][j],nums,dp)));
        }
        return 0;
    }
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            ans=max(ans,solve(i,0,-1,grid,dp));
        }
        return ans-1;
    }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // priority_queue<pair<int,int>>pq;
        vector<vector<int>>dp(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));
        dp[0][0]=0;
        int s1=0,s2=0;
        priority_queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            auto i=q.top();
            q.pop();
            int ir[]={0,1,0,-1};
            int ic[]={1,0,-1,0};
            for(int x=0;x<4;x++){
                int i1=i.second.first+ir[x];
                int j1=i.second.second+ic[x];
                if(i1>-1 && i1<moveTime.size() && j1>-1 && j1<moveTime[0].size()){
                    if(max(dp[i.second.first][i.second.second],moveTime[i1][j1])+1<dp[i1][j1]){
                        dp[i1][j1]=max(dp[i.second.first][i.second.second],moveTime[i1][j1])+1;
                        q.push({dp[i1][j1],{i1,j1}});
                    }
                }
            }
        }
        if(dp[moveTime.size()-1][moveTime[0].size()-1]==INT_MAX)return -1;
        return dp[moveTime.size()-1][moveTime[0].size()-1];
        
    }
};
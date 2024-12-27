class Solution {
public:
    bool solve(int i,string s,unordered_set<string>&st,vector<int>&dp){
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        int res=0;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(st.find(temp)!=st.end())res|=solve(j+1,s,st,dp);
        }
        return dp[i]=res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto i:wordDict)st.insert(i);
        vector<int>dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};
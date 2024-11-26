class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>store(n,0);
        for(auto i:edges){
            store[i[1]]++;
        }
        int res=-1;
        for(int i=0;i<n;i++){
            cout<<store[i]<<" ";
            if(res==-1 && store[i]==0)res=i;
            else if(res!=-1 && store[i]==0)return -1;
        }
        return res;
    }
};
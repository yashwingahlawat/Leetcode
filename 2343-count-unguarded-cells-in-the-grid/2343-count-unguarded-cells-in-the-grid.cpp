class Solution {
public:
    void solve(int i,int j,vector<vector<int>>& store,vector<vector<int>>&vis,int m,int n){
        for(int x=i+1;x>=0 && x<m;x++){
            // cout<<i<<" "<<j<<endl;
            if(store[x][j]==2||vis[x][j]==1||vis[x][j]==3)break;
            vis[x][j]+=1;
        }
        for(int x=i-1;x>=0 && x<m;x--){
            // cout<<i<<" "<<j<<endl;
            if(store[x][j]==2||vis[x][j]==1||vis[x][j]==3)break;
            vis[x][j]+=1;
        }
        for(int x=j+1;x>=0 && x<n;x++){
            // cout<<i<<" "<<j<<endl;
            if(store[i][x]==2||vis[i][x]==2||vis[i][x]==3)break;
            vis[i][x]+=2;
        }
        for(int x=j-1;x>=0 && x<n;x--){
            // cout<<i<<" "<<j<<endl;
            if(store[i][x]==2||vis[i][x]==2||vis[i][x]==3)break;
            vis[i][x]+=2;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>store(m,vector<int>(n,0));
        for(auto i:guards){
            store[i[0]][i[1]]=1;
        }
        for(auto i:walls){
            store[i[0]][i[1]]=2;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(store[i][j]==1)solve(i,j,store,vis,m,n);
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<vis[i][j]<<" ";
                if(!store[i][j] && !vis[i][j]){
                    // cout<<1;
                    res++;
                }
                // else cout<<0;
            }
            // cout<<endl;
        }
        return res;
    }
};
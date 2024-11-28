class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dist[0][0]=grid[0][0];
        q.push({dist[0][0],{0,0}});
        while(!q.empty()){
            auto i=q.top();
            q.pop();
            int r[4]={1,0,-1,0};
            int c[4]={0,1,0,-1};
            for(int x=0;x<4;x++){
                int ir=i.second.first+r[x];
                int ic=i.second.second+c[x];
                if(ir>=0 && ir<grid.size() && ic>=0 && ic<grid[0].size() && dist[i.second.first][i.second.second]+grid[ir][ic]<dist[ir][ic]){
                    dist[ir][ic]=dist[i.second.first][i.second.second]+grid[ir][ic];
                    q.push({dist[ir][ic],{ir,ic}});
                }
            }
        }
        return dist[grid.size()-1][grid[0].size()-1];
    }
};
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        
        // for(auto i:queries){
        //     adj[i[0]].push_back(i[1]);
        // }
        // queue<int>q;
        vector<int>dist(n,0);
        vector<int>res;
        for(int i=0;i<dist.size();i++)dist[i]=i;
        for(auto i:queries){
            adj[i[0]].push_back(i[1]);
            if(dist[i[0]]+1<dist[i[1]]){
                queue<int>q;
                dist[i[1]]=dist[i[0]]+1;
                q.push(i[1]);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(auto y:adj[x]){
                        if(dist[x]+1<dist[y]){
                            dist[y]=dist[x]+1;
                            q.push(y);
                        }
                    }
                }
            }
            res.push_back(dist[n-1]);
        }
        return res;
        // dist[0]=0;
        // d
    }
};
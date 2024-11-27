class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>res;
        vector<int>dist(n,0);
        for(int i=0;i<n;i++)dist[i]=i;
        for(auto i:queries){
            queue<int>q;
            adj[i[0]].push_back(i[1]);
            q.push(i[0]);
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto i:adj[x]){
                    if(dist[x]+1<dist[i]){
                        dist[i]=dist[x]+1;
                        q.push(i);
                    }
                }
            }
            res.push_back(dist[n-1]);
        }
        return res;
    }
};
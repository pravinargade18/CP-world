class Solution {
private:
    void dfs(int node,int parent,unordered_map<int,list<int>>&adj,vector<int>&disc,vector<int>&low,unordered_map<int,bool>&visited,int timer,vector<vector<int>>&bridges){
        visited[node]=true;
        disc[node]=low[node]=timer;
        timer++;
        
        for(auto nbr:adj[node]){
            if(nbr==parent){
                continue;
            }
            
            if(!visited[nbr]){
                dfs(nbr,node,adj,disc,low,visited,timer,bridges);
                low[node]=min(low[node],low[nbr]);
                
                if(low[nbr]>disc[node]){
                    bridges.push_back({nbr,node});
                }
                
            }
            else{
                low[node]=min(low[node],disc[nbr]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer=0;
        vector<int>disc(n);
        vector<int>low(n);
        unordered_map<int,bool>visited(n);
        int parent=-1;
        vector<vector<int>>bridges;
        for(int i=0;i<n;i++){
            dfs(0,parent,adj,disc,low,visited,timer,bridges);

        }
        return bridges;
    }
};

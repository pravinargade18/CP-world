void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjList ,vector<int>&component){
    component.push_back(node);
    visited[node]=1;
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,visited,adjList,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>ans;
    unordered_map<int,list<int>>adjList;
    unordered_map<int,bool>visited;
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i,visited,adjList,component);
            ans.push_back(component);
        }
    }
    return ans;
}

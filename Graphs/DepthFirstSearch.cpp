#include <bits/stdc++.h> 
void createAdjList(unordered_map<int,set<int>>&adjList,int vertex,vector<pair<int, int>> edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
        
    }
}


void bfsTraversal(unordered_map<int,set<int>>&adjList,unordered_map<int,bool>&visited,vector<int>&ans,int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
            
        }
        
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>>adjList;
    unordered_map<int,bool>visited;
    vector<int>ans;
    
    createAdjList(adjList,vertex,edges);
    for(int i=0;i<vertex;i++){   //for loop because it is disconnected graph so we have to consider each component of the graph if it is not disconnected then we can continue without for loop
        if(!visited[i]){
            bfsTraversal(adjList,visited,ans,i);
        }
        
    }
    return ans;
}

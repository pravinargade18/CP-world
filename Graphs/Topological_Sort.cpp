// topological sort is only available for directed acyclic graph
#include <bits/stdc++.h> 

void topoSort(int node,vector<int>adjList[], vector<bool>&visited,stack<int>&s){
    visited[node]=1;
    for(auto i:adjList[node]){
        if(!visited[i]){
            topoSort(i,adjList,visited,s);
        }
    }
    s.push(node);
    
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>adjList[v];
    vector<bool>visited(v,0);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].push_back(v);
    }
    stack<int>s;
    vector<int>ans;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,adjList,visited,s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
    
}

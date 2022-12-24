#include<bits/stdc++.h>
bool detectCycle(int node,unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited){
    visited[node]=1;
    dfsVisited[node]=1;
    for(auto i:adjList[node]){
        if(!visited[i]){
            bool cycleDetected=detectCycle(i,adjList,visited,dfsVisited);
            if(cycleDetected){
                return true;
            }
        }
        else if(dfsVisited[i]){
            return true;
        }
    }
    dfsVisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
     unordered_map<int,list<int>>adjList;
     unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);  //only one side direction as it is directed graph
        
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=detectCycle(i,adjList,visited,dfsVisited);
            if(ans){
                return true;
            }
        }
    }
    return false;
}

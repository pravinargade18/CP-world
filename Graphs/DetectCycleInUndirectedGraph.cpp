// using breadth first search

#include<bits/stdc++.h>
bool isCyclePresent(unordered_map<int,list<int>>&adjList,unordered_map<int ,bool>&visited,int node,int parent){
     visited[node]=1;
    
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected=isCyclePresent(adjList,visited,neighbour,node);
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
    
    
    
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>>adjList;
    for(int i=0;i<edges.size();i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    unordered_map<int ,bool>visited;
    unordered_map<int,int>parent;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCyclePresent(adjList,visited,i,-1);  // parent is -1 for first node
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";
}

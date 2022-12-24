//We will detect cycle using the logic of topological sort 
// in topological sort we get the all nodes as cycle is not present but we don't get all the nodes count then it means cycle is present

#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
      unordered_map<int,list<int>>adjList;
      vector<int>indegree(n);
        for(int i=0;i<edges.size();i++){
                int u=edges[i].first-1;
                int v=edges[i].second-1;
                adjList[u].push_back(v);
        }
    
//         find indegrees
        for(auto i:adjList){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
         
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
    
    int cnt=0;
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cnt++;
        for(auto neighbour:adjList[front]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
        }
    }
    if(cnt==n){
        return false;
    }
    else{
        return true;
    }
    
    
}

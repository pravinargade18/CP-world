#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>>adjList;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].push_back(v);
    }
    
//     find indegree
    vector<int>indegree(v);
    for(auto i:adjList){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    
    //push all the nodes in queue who has indegree 0
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    vector<int>ans;
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        
//         check for all neighbours indegree if 0 then push that node in queue
        for(auto neighbour:adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    
    return ans;
    
}

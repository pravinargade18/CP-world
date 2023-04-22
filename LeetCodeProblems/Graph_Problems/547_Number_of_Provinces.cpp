class Solution {
private:
    void dfs(int node,unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited){
        visited[node]=1;
        for(auto i:adjList[node]){
            if(!visited[i]){
                dfs(i,adjList,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // step-1 convert adjMatrix into adjList
        int size=isConnected.size();
        unordered_map<int,list<int>>adjList;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        // step-2 run loop for each component of the graph
        unordered_map<int,bool>visited;
        int count=0;
        for(int i=0;i<size;i++){
            if(!visited[i]){
                count++;
                dfs(i,adjList,visited);
            }
        }
        return count;
    }
};

class Solution {
public:
    bool pathExist=false;
    void createAdjList(unordered_map<int,set<int>>&adjList,int vertex,vector<vector<int>> edges){
            for(int i=0;i<edges.size();i++){
                adjList[edges[i][0]].insert(edges[i][1]);
                adjList[edges[i][1]].insert(edges[i][0]);

            }
    }


void dfsTraversal(unordered_map<int,set<int>>&adjList,unordered_map<int,bool>&visited,int source,int destination){
        visited[source]=1;
        for(auto i:adjList[source]){
            if(!visited[i]){
                if(i==destination){
                    pathExist= true;
                }
                dfsTraversal(adjList,visited,i,destination);
            }
        }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        unordered_map<int,set<int>>adjList;
        unordered_map<int,bool>visited;

        createAdjList(adjList,n,edges);
        dfsTraversal(adjList,visited,source,destination);
        return pathExist;
        
    }
};

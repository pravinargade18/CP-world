// User function Template for C++
class Solution {
    private:
        void topoSort(int node,unordered_map<int,bool>&visited,unordered_map<int,list<pair<int,int>>>&adjList,stack<int>&st){
            visited[node]=1;
            for(auto i:adjList[node]){
                int neighbour=i.first;
                if(!visited[neighbour]){
                    topoSort(neighbour,visited,adjList,st);
                }
            }
            st.push(node);
        }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         unordered_map<int,list<pair<int,int>>>adjList;
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adjList[u].push_back({v,wt});
        }
        
        unordered_map<int,bool>visited;
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                topoSort(i,visited,adjList,st);
            }
        }
        
        
        // find shortest distances 
        vector<int> dist(N);
        for(int i=0;i<N;i++){
            dist[i]=1e9;   //initialize the array with max value initially
        }
        
        dist[0]=0;  //for initial node the distance will be 0
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            for(auto i:adjList[node]){
                int v=i.first;
                int wt=i.second;
                
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){

            if(dist[i]==1e9){

                dist[i]=-1;

            }

        }
        
        return dist;
    }
};

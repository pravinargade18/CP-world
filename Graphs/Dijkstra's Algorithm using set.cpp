class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>s;
        //using set
        vector<int>dist(V,1e9);
        dist[S]=0;
        s.insert({0,S});
        
        while(!s.empty()){
            auto it=*(s.begin());
            int dis=it.first;
            int node=it.second;
            
            s.erase({dis,node});  //remove first entry
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edgeWt=it[1];
                
                if(dis+edgeWt<dist[adjNode]){
                    
                    if(dist[adjNode]!=1e9){
                        s.erase({dist[adjNode],adjNode});
                    }
                    
                    dist[adjNode]=dis+edgeWt;
                    s.insert({dist[adjNode],adjNode});
                }
            }
            
        }
        return dist;
    }
};

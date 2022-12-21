
#include <bits/stdc++.h>

using namespace std;

class graph{
    public:
       unordered_map<int,list<int>>adj;   //adjacency List
       
       void addEdge(int u,int v,bool direction){
        //   direction=0 ->undirected graph
        // direction=1 ->directed graph
        
        // create an edge between u and v
         adj[u].push_back(v);
         if(direction==0){
             adj[v].push_back(u);  //if it is undirected graph then edges can be form for both directions from u->v and v->u
         }
       }
       
       void printAdjList(){
           for(auto i:adj){
               cout<<i.first<<"-> ";
               for(auto j:i.second){
                   cout<<j<<", ";
               }
               cout<<endl;
           }
       }
     
};
int main()
{
    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;
    
    int m;
    cout<<"Enter the number of edges:";
    cin>>m;
    
    
    graph g;
    
    for(int i=0;i<m;i++){   //for every edge get two nodes
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);  //undirected
    }
    
    // printing graph
    g.printAdjList();

    return 0;
}

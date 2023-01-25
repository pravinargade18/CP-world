#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }

    // initialize 3 data structures such as key,MST & Parent
    vector<int>key(n+1,INT_MAX);  //n+1 becoz nodes start from 1
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);

    //Start the prims algorithm now
    key[1]=0;
    parent[1]=-1;

    //now check for minimum value in key vector
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if(mst[j]==false && key[j]<mini){
                u=j;
                mini=key[j];
            }
        }

        mst[u]=true;
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;

            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }


    vector<pair<pair<int, int>, int>>result;
    for(int i=2;i<=n;i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;

}

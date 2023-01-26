// The disjoint method is used to check whether any two nodes of graph lies in the same componenet or not the graph is dynamic and it's structure can be changed at any time

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);   //initalize rank array with 0's
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;           //initially parent of the node will be the same node itself 
        }
    }

    //Path compression
    int findUPar(int node) {
        if (node == parent[node])            //if we found that the node is parent of itself then we will return that node itself as a ultimate parent
            return node;
        return parent[node] = findUPar(parent[node]);    //to assign ultimate parent to all the nodes between the actual ultimate parent and node for which we are finding ultimate parent
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);              // s1-->>first find ultimate parent of nodes
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;                     //s2-->if ultimate parents are same then do nothing
        if (rank[ulp_u] < rank[ulp_v]) {                //if ultimate parents are not same then attach node which is having smaller rank to the node having larger rank
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {                            //if ultimate parents are different and ranks of ultimate parents are same then attach any node to any node just increment the rank of node by 1 to which we are connecting other node
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}

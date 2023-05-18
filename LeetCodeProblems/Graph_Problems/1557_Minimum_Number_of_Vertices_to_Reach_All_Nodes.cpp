class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int>indegree;
        
        for(auto edge: edges){
            indegree[edge[1]]++;    //find indegree of every node 1 coz second elements incoming edge needed to find
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

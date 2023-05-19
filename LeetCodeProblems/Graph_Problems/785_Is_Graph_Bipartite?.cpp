class Solution {
private:
    bool check(int start,int size,vector<int>color,vector<vector<int>> graph){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            
            int front=q.front();
            q.pop();
            for(auto it:graph[front]){
            
            if(color[it]==-1){
                color[it]=!color[front];
                q.push(it);
            }
            else if(color[it]==color[front]){
                return false;
            }
                
        }
        }
        
        return true;
    }
   
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int size=graph.size();
        vector<int>color(size,-1);
        
        for(int i=0;i<size;i++){
            if(color[i]==-1){
                if(!check(i,size,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};

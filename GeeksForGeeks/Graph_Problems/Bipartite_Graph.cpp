class Solution {
private:
    bool check(int start,int n,vector<int>adj[],int color[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto i:adj[front]){
                if(color[i]==-1){
                    color[i]=!color[front];
                    q.push(i);
                }
                else if(color[i]==color[front]){
                    return false;
                }
            }
        }
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    
	    for(int i=0;i<V;i++) color[i]=-1;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,V,adj,color)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

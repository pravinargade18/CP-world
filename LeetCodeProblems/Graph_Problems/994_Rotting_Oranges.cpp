class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int visited[n][m];
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    // {{row,col},time}
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int time=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(t,time);
            q.pop();
            //visiting all 4 neighbours
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                // orange should be fresh & shouldn't be rotten
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol]=2;
                } 
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2 && grid[i][j]==1){  //if any single fresh orange left then return -1
                    return -1;
                }
            }
        }
        return time;
    }
};

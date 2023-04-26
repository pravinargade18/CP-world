class Solution {
private:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&visited){
        visited[row][col]=1;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({row,col});
        
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            
            // traverse all the neighbours of the element if it is land and we have to traverse all sides of the element from the starting element this is a shortcut to traverse all 8 sides of the element in matrix
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(abs(delrow)==abs(delcol)){continue;}
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // we will solve it using kind of graph component solving problem
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};

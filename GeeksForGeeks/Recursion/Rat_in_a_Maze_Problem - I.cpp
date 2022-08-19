class Solution{
    private:
    
        bool isSafe(vector<vector<int>> &m,int n, vector<vector<int>> visited,int x,int y){
            
        //   we have to check all conditions to check wheather we can move or not
        // first and second condition is to check we are not going outside the matrix
        // third condition is to check that next position is not visited already
        // fourth condition is to check next position on which we want to move is 1 means non-blocked
            if((x>=0 && x<n) &&  (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
                return true;
            }
            else{
                return false ;
            }
        }
        
        void solve(vector<vector<int>> &m,int n, vector<string>& ans, vector<vector<int>> visited,string path,int x,int y){
            // base case 
            //if rat reaches at destination then push back path into ans and return 
            if(x==n-1 && y==n-1){
                ans.push_back(path);
                return;
            }
            
            // as we checked condition for starting position first and then we reached here means we are not at starting position means at some other position 
            visited[x][y]=1;
            
            //for down
            int newx=x+1;
            int newy=y;
            if(isSafe(m,n,visited,newx,newy)){
                path.push_back('D');
                solve(m,n,ans,visited,path,newx,newy);
                path.pop_back();        //backtracking
            }
            
            // for left
            newx=x;
            newy=y-1;
            if(isSafe(m,n,visited,newx,newy)){
                path.push_back('L');
                solve(m,n,ans,visited,path,newx,newy);
                path.pop_back();            //backtracking
            }
            
            // for right
            newx=x;
            newy=y+1;
            if(isSafe(m,n,visited,newx,newy)){
                path.push_back('R');
                solve(m,n,ans,visited,path,newx,newy);
                path.pop_back();           //backtracking
            }
            
            // for up
            newx=x-1;
            newy=y;
            if(isSafe(m,n,visited,newx,newy)){
                path.push_back('U');
                solve(m,n,ans,visited,path,newx,newy);
                path.pop_back();    //backtracking
            }
            
            
            
            visited[x][y]=0;  //backtracking
        }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string path="";
        
        //in beggining rat is at position x=0 and y=0
        int srcx=0;
        int srcy=0;
        
        // edge case i.e.  if starting position itself contains 0 then rat can't move further
        if(m[srcx][srcy]==0){
            return ans;
        }
        
        // visited array initialised with 0 it to keep track of rat so that no infinite looping can happen in between two adjacent 1's
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        solve(m,n,ans,visited,path,srcx,srcy);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

  

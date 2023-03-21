class Solution {
public:
    void addSolution(vector<vector<string>>&ans,vector<string>& board,int n){
        vector<string>temp;
        string s="";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s+=board[i][j];
            }
            temp.push_back(s);
            s="";
        }
        ans.push_back(temp);
    }
    
    bool isSafe(int row,int col,vector<string>& board,int n){
        int x=row;
        int y=col;
        
        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }
        
        x=row;
        y=col;
        
        while(y>=0 && x>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
            x--;
        }
        
        x=row;
        y=col;
        
        while(y>=0 && x<n){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
            x++;
        }
        
        return true;
    }
    
    void solve(int col,vector<vector<string>>&ans,vector<string>& board,int n){
        if(col==n){
            addSolution(ans,board,n);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                // backtrack
                board[row][col]='.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n, string(n, '.'));
        vector<vector<string>>ans;
        int col=0;
        solve(col,ans,board,n);
        return ans;
    }
};

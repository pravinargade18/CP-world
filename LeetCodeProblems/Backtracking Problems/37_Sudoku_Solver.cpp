class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& board,int val){
        int n=board.size();
        for(int i=0;i<n;i++){
            
            if(board[row][i]==val || board[i][col]==val){
                return false;
            }
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(board[i][j]=='.'){
                    for(int val=1;val<=9;val++){
                        if(isSafe(i,j,board,char(val+48))){
                            board[i][j]=char(val+48);
                            bool furtherSolutionPossible=solve(board);
                            if(furtherSolutionPossible){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                            
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

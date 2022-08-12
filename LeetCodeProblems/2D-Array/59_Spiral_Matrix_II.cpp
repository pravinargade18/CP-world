class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>>mat(n,vector<int>(n)) ;
        int row=n,col=n;
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        int ele=1;
        int total=row*col;
        
        while(ele<=total){
            for(int i=startingCol;i<=endingCol && ele<=total;i++){
                mat[startingRow][i]=ele++;
            }
            startingRow++;
            
            for(int i=startingRow;i<=endingRow && ele<=total;i++){
                mat[i][endingCol]=ele++;
            }
            endingCol--;
            
            for(int i=endingCol;i>=startingCol && ele<=total;i--){
                mat[endingRow][i]=ele++;
            }
            endingRow--;
            
            for(int i=endingRow;i>=startingRow && ele<=total;i--){
                mat[i][startingCol]=ele++;
            }
            startingCol++;
            
        }
        return mat;
    }
};

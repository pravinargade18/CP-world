class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int row=arr.size();
        int col=arr[0].size();
        int count=0;
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        int total=row*col;
        while(count<total){
            for(int i=startingCol;i<=endingCol && count<total;i++){
                if(arr[startingRow][i]==target){
                    return true;
                }
                count++;
            }
            startingRow++;
            
            for(int i=startingRow;i<=endingRow && count<total;i++){
                if(arr[i][endingCol]==target){
                    return true;
                    }
                count++;
            }
            endingCol--;
            
            for(int i=endingCol;i>=startingCol && count<total;i--){
                if(arr[endingRow][i]==target){
                    return true;
                }
                count++;
            }
            
            endingRow--;
            
            for(int i=endingRow;i>=startingRow && count<total;i--){
                if(arr[i][startingCol]==target){
                return true;
                }
                count++;
            }
            startingCol++;
        
        
        }
            return false;
    }
};

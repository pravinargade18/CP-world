class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int>v;
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
                v.push_back(arr[startingRow][i]);
                count++;
            }
            startingRow++;
            
            for(int i=startingRow;i<=endingRow && count<total;i++){
                v.push_back(arr[i][endingCol]);
                count++;
            }
            endingCol--;
            
            for(int i=endingCol;i>=startingCol && count<total;i--){
                v.push_back(arr[endingRow][i]);
                count++;
            }
            endingRow--;
            
            for(int i=endingRow;i>=startingRow && count<total;i--){
                v.push_back(arr[i][startingCol]);
                count++;
            }
            startingCol++;
        
        }
        return v;
        
    }
};

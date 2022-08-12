class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int row=matrix.size();
        int col=matrix[0].size();
        int rowIndex=0;
        int colIndex=col-1;  //we will start from element which is at first row and last column
        while(rowIndex<row  && colIndex>=0){
            int element=matrix[rowIndex][colIndex]; //we will start from element which is at 0th row and last column
            if(element==target){
                return true;
            }
            if(target<element){   //if element is less than element then the target will be on left side of the element in that row because elements less than element only lies on left side of that row only
                colIndex--;
            }
            else{
                rowIndex++;  //the target may be in next row because elements greater than only lies in next rows
            }
            
        }
        return false;
    }
};


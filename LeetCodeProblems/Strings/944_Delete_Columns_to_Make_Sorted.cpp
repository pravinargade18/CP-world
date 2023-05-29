class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row=strs.size();
        int col=strs[0].size();
        int count=0;
        for(int j=0;j<col;j++){   //check for each column
            for(int i=1;i<row;i++){
                if(strs[i][j] < strs[i-1][j]){  //In each column compare characters of rows i.e compare next character with previous character if we found such character first time in that column then increase count and break loop for that particular column
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

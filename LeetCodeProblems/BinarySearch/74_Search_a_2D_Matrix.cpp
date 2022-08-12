class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int row=arr.size();
        int col=arr[0].size();
        int s=0;
        int e=(row*col)-1;
        int mid=0;
        while(s<=e){
            mid=s+(e-s)/2;  //to find the index of the row divide it by number of column 
            //and to find the column no divide the mid index by col number
            int ele=arr[mid/col][mid%col];
            if(ele==target){
                return true;
                }
            else if(target<ele){     //in this code mid is the middle element
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
};

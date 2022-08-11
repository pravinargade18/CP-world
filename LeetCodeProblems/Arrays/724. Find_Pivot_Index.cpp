class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int rightsum=accumulate(arr.begin(),arr.end(),0);
        int leftsum=0;
        for(int i=0;i<arr.size();i++){
            rightsum-=arr[i];
            if(leftsum==rightsum){
                return i; 
            }
            leftsum+=arr[i];
            
        }
        return -1;
    }
};

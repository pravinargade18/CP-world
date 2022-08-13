class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int j=1;
        for(int i=0;i<n;i++){
            if(j!=arr[i]){
                return j;
                
            }
            j++;
        }
    }
};

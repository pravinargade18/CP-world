class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
       int s=0;
       int e=n-1;
       int mid=0;
       
       while(s<=e){
           mid=s+(e-s)/2;
           if(arr[mid]==k){
               return mid;
           }
           else if(k<arr[mid]){
               e=mid-1;
           }
           else{
               s=mid+1;
           }
       }
       return -1;
    }
};

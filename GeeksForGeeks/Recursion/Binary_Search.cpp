class Solution {
  public:
    int binarySearchRecursive(int arr[],int s,int e,int k){
       if(s>e){
           return -1;
       }
       
        int mid=s+(e-s)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(k>arr[mid]){
            binarySearchRecursive(arr,mid+1,e,k);
        }
        else{
            binarySearchRecursive(arr,s,mid-1,k);
        }
        
    }
    int binarysearch(int arr[], int n, int k) {
        int pos=binarySearchRecursive(arr,0,n-1,k);
        return pos;
        
    }
};

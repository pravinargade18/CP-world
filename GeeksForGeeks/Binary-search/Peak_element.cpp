class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       int s=0;
       int e=n-1;
       int mid=0;
       while(s<e){
           mid=s+(e-s)/2;
           if(arr[mid]<arr[mid+1]){
               s=mid+1;
           }
           else{
              e=mid; 
           }
       }
       return s;
    }
};

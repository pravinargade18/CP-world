class Solution {
public:
    int binarySearch(vector<int> arr,int s,int e,int k){
        if(s>e){
            return -1;
        }
        int mid=s+(e-s)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(k<arr[mid]){
            e=mid-1;
            return binarySearch(arr,s,e,k);
        }
        else{
            s=mid+1;
            return binarySearch(arr,s,e,k);
        }
        
    }
    int search(vector<int>& nums, int target) {
       int pos=binarySearch(nums,0,nums.size()-1,target);
        return pos;
    }
};

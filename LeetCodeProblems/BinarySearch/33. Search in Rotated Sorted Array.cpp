class Solution {
public:
//     function to get the position of pivot element
    int findPivot(vector<int>& nums,int n){
        int s=0;
        int e=n-1;
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
    
//     applying binary search on search space
    int binarySearch(vector<int>& nums,int s,int e, int k){
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==k){
                return mid;
            }
            else if(k>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums,n);
        int ans=-1;
        if(target>=nums[pivot]  && target<=nums[n-1]){
            ans=binarySearch(nums,pivot,n-1,target);
        }
        else{
            ans=binarySearch(nums,0,pivot-1,target);
        }
        return ans;
    }
};

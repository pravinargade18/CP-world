class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int l=1;
       int len=nums.size();
        for(int r=1;r<len;r++){
            if(nums[r]!=nums[r-1]){
                nums[l]=nums[r];
                l++;
            }
        }
        return l;
    }
};
